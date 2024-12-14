#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "Observer.h"
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <iostream>

// Глобальные переменные для синхронизации
std::shared_mutex npcsMutex;
std::condition_variable_any cv;
bool gameRunning = true;

// Функция для получения случайного типа NPC
std::string getRandomType() {
    static const std::vector<std::string> types = {"Knight", "Elf", "Druid"};
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, types.size() - 1);
    return types[dist(gen)];
}

// Функция для передвижения NPC
void moveNPCs(std::vector<std::shared_ptr<NPC>>& npcs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);

    while (gameRunning) {
        {
            std::lock_guard<std::shared_mutex> lock(npcsMutex); // Используем lock_guard для записи
            for (auto& npc : npcs) {
                int dx = dist(gen);
                int dy = dist(gen);
                npc->move(dx, dy);

                // Проверка на расстояние убийства
                for (auto& other : npcs) {
                    if (npc != other && npc->isWithinKillDistance(other.get())) {
                        cv.notify_one(); // Уведомление потока боев
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// Функция для боев
void battleNPCs(std::vector<std::shared_ptr<NPC>>& npcs, FileLogger& fileLogger) {
    while (gameRunning) {
        std::unique_lock<std::shared_mutex> lock(npcsMutex);
        cv.wait(lock, []{ return !gameRunning; }); // Ожидаем уведомления или завершения игры

        for (auto it = npcs.begin(); it != npcs.end();) {
            auto npc1 = *it;
            bool alive = true;

            for (auto it2 = npcs.begin(); it2 != npcs.end();) {
                auto npc2 = *it2;
                if (npc1 != npc2 && npc1->isWithinKillDistance(npc2.get())) {
                    // Бой между NPC
                    fileLogger.update("Battle started between " + npc1->getType() + " " + npc1->getName() + " and " + npc2->getType() + " " + npc2->getName());
                    if (npc1->fight(npc2.get())) {
                        fileLogger.update(npc1->getType() + " " + npc1->getName() + " killed " + npc2->getType() + " " + npc2->getName());
                        it2 = npcs.erase(it2); // Удаление проигравшего NPC
                    } else {
                        fileLogger.update(npc2->getType() + " " + npc2->getName() + " killed " + npc1->getType() + " " + npc1->getName());
                        alive = false;
                        break;
                    }
                } else {
                    ++it2;
                }
            }

            if (!alive) {
                it = npcs.erase(it); // Удаление проигравшего NPC
            } else {
                ++it;
            }
        }
    }
}

// Функция для отображения карты
void printMap(std::vector<std::shared_ptr<NPC>>& npcs) {
    while (gameRunning) {
        {
            std::shared_lock<std::shared_mutex> lock(npcsMutex); // Используем shared_lock для чтения
            std::cout << "Map:" << std::endl;
            for (const auto& npc : npcs) {
                npc->print();
            }
            std::cout << "-------------------------" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::vector<std::shared_ptr<NPC>> npcs;

    // Создание объекта FileLogger
    FileLogger fileLogger("log.txt");

    // Создание 50 NPC в случайных локациях
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    for (int i = 0; i < 50; ++i) {
        npcs.push_back(NPCFactory::createNPC(getRandomType(), "NPC" + std::to_string(i), dist(gen), dist(gen)));
    }

    // Создание потоков
    std::thread moveThread(moveNPCs, std::ref(npcs));
    std::thread battleThread(battleNPCs, std::ref(npcs), std::ref(fileLogger));
    std::thread printThread(printMap, std::ref(npcs));

    // Ожидание завершения игры через 30 секунд
    std::this_thread::sleep_for(std::chrono::seconds(30));
    gameRunning = false;
    cv.notify_all(); // Уведомляем все потоки о завершении игры

    // Остановка потоков
    moveThread.join();
    battleThread.join();
    printThread.join();

    // Вывод списка выживших NPC
    std::cout << "Survivors:" << std::endl;
    for (const auto& npc : npcs) {
        npc->print();
    }

    return 0;
}