#include <gtest/gtest.h>
#include "NPC.h"
#include "NPCFactory.h"
#include "BattleVisitor.h"

TEST(NPCFactoryTest, CreateNPC) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 150, 150);
    auto druid = NPCFactory::createNPC("Druid", "Merlin", 200, 200);

    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(druid->getType(), "Druid");
}

TEST(NPCTest, MoveNPC) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    knight->move(10, 10);
    EXPECT_EQ(knight->getX(), 110);
    EXPECT_EQ(knight->getY(), 110);
}

TEST(NPCTest, KillDistance) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 110, 110);
    EXPECT_TRUE(knight->isWithinKillDistance(elf.get()));
}

TEST(NPCTest, Fight) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 110, 110);
    EXPECT_TRUE(knight->fight(elf.get()));
}