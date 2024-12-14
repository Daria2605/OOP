#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "Observer.h"
#include <vector>
#include <memory>

int main() {
    // Create NPCs
    std::vector<std::shared_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Knight", "Arthur", 100, 100));
    npcs.push_back(NPCFactory::createNPC("Elf", "Legolas", 150, 150));
    npcs.push_back(NPCFactory::createNPC("Druid", "Merlin", 200, 200));

    // Print NPCs
    std::cout << "Initial NPCs:" << std::endl;
    for (const auto& npc : npcs) {
        npc->print();
    }

    // Create observers
    FileLogger fileLogger("log.txt");
    ScreenLogger screenLogger;

    // Battle simulation
    BattleVisitor battleVisitor(100);
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (battleVisitor.fight(npcs[i], npcs[j])) {
                std::string event = npcs[i]->getName() + " fights " + npcs[j]->getName();
                fileLogger.update(event);
                screenLogger.update(event);
            }
        }
    }

    return 0;
}