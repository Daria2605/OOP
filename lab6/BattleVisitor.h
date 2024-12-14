#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include "NPC.h"
#include <memory>
#include <cmath>

class BattleVisitor {
private:
    int range;

public:
    BattleVisitor(int range) : range(range) {}

    bool fight(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2) {
        int dx = npc1->getX() - npc2->getX();
        int dy = npc1->getY() - npc2->getY();
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance > range) return false; // Too far to fight

        if (npc1->getType() == "Knight" && npc2->getType() == "Elf") {
            return true; // Knight kills Elf
        } else if (npc1->getType() == "Elf" && npc2->getType() == "Knight") {
            return true; // Elf kills Knight
        } else if (npc1->getType() == "Elf" && npc2->getType() == "Druid") {
            return true; // Elf kills Druid
        } else if (npc1->getType() == "Druid" && npc2->getType() == "Druid") {
            return true; // Both Druids die
        }

        return false; // Both die in other cases
    }
};

#endif // BATTLEVISITOR_H