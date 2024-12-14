#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include "NPC.h"
#include <memory>

class BattleVisitor {
public:
    bool fight(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2) {
        return npc1->fight(npc2.get());
    }
};

#endif // BATTLEVISITOR_H