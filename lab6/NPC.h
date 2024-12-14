#ifndef NPC_H
#define NPC_H

#include <string>
#include <iostream>
#include <cmath>
#include <random>

class NPC {
protected:
    std::string name;
    int x, y;
    int moveDistance;  // Расстояние хода
    int killDistance;  // Расстояние убийства

public:
    NPC(const std::string& name, int x, int y, int moveDistance, int killDistance)
        : name(name), x(x), y(y), moveDistance(moveDistance), killDistance(killDistance) {}

    virtual ~NPC() = default;

    virtual std::string getType() const = 0;

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    bool isWithinKillDistance(const NPC* other) const {
        int dx = x - other->x;
        int dy = y - other->y;
        return std::sqrt(dx * dx + dy * dy) <= killDistance;
    }

    bool fight(const NPC* other) const {
        int attackPower = rollDice(); // Сила атаки
        int defensePower = other->rollDice(); // Сила защиты
        return attackPower > defensePower;
    }

    int rollDice() const {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dist(1, 6);
        return dist(gen);
    }

    void print() const {
        std::cout << getType() << " " << name << " at (" << x << ", " << y << ")" << std::endl;
    }

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getMoveDistance() const { return moveDistance; }
    int getKillDistance() const { return killDistance; }
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) : NPC(name, x, y, 30, 10) {}
    std::string getType() const override { return "Knight"; }
};

class Elf : public NPC {
public:
    Elf(const std::string& name, int x, int y) : NPC(name, x, y, 10, 50) {}
    std::string getType() const override { return "Elf"; }
};

class Druid : public NPC {
public:
    Druid(const std::string& name, int x, int y) : NPC(name, x, y, 10, 10) {}
    std::string getType() const override { return "Druid"; }
};

#endif // NPC_H