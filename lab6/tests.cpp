#include <gtest/gtest.h>
#include "NPC.h"
#include "NPCFactory.h"
#include "BattleVisitor.h"

// Тест создания NPC
TEST(NPCFactoryTest, CreateNPC) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    auto druid = NPCFactory::createNPC("Druid", "Merlin", 200, 200);
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 150, 150);

    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(druid->getType(), "Druid");
    EXPECT_EQ(elf->getType(), "Elf");

    EXPECT_EQ(knight->getName(), "Arthur");
    EXPECT_EQ(druid->getName(), "Merlin");
    EXPECT_EQ(elf->getName(), "Legolas");

    EXPECT_EQ(knight->getX(), 100);
    EXPECT_EQ(knight->getY(), 100);
}

// Тест сражения NPC
TEST(BattleVisitorTest, Fight) {
    auto knight = NPCFactory::createNPC("Knight", "Arthur", 100, 100);
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 150, 150);
    auto druid = NPCFactory::createNPC("Druid", "Merlin", 200, 200);

    BattleVisitor visitor(100);

    // Knight vs Elf
    EXPECT_TRUE(visitor.fight(knight, elf));

    // Elf vs Druid
    EXPECT_TRUE(visitor.fight(elf, druid));

    // Druid vs Druid
    auto druid2 = NPCFactory::createNPC("Druid", "Merlin2", 200, 200);
    EXPECT_TRUE(visitor.fight(druid, druid2));
}