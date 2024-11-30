#include <gtest/gtest.h>
#include "FixedBlockMemoryResource.hpp"
#include "ForwardList.hpp"
#include <string>

struct ComplexType {
    int a_;
    double b_;
    std::string c_;

    ComplexType(int a, double b, const std::string& c)
        : a_(a), b_(b), c_(c) {}
};

// Тесты для FixedBlockMemoryResource
TEST(FixedBlockMemoryResourceTest, AllocationDeallocation) {
    FixedBlockMemoryResource mr(1024);

    void* ptr1 = mr.allocate(32);
    EXPECT_NE(ptr1, nullptr);

    void* ptr2 = mr.allocate(64);
    EXPECT_NE(ptr2, nullptr);

    mr.deallocate(ptr1, 32);
    mr.deallocate(ptr2, 64);

    void* ptr3 = mr.allocate(32);
    EXPECT_EQ(ptr3, ptr1); // Должен переиспользовать освобожденный блок

    mr.deallocate(ptr3, 32);
}

// Тесты для ForwardList с типом int
TEST(ForwardListTest, IntPushFront) {
    FixedBlockMemoryResource mr(1024);
    ForwardList<int> list(&mr);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}

TEST(ForwardListTest, IntPopFront) {
    FixedBlockMemoryResource mr(1024);
    ForwardList<int> list(&mr);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.pop_front();
    auto it = list.begin();
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, list.end());
}

// Тесты для ForwardList с ComplexType
TEST(ForwardListTest, ComplexTypeOperations) {
    FixedBlockMemoryResource mr(1024);
    ForwardList<ComplexType> list(&mr);

    list.push_front(ComplexType(1, 1.1, "one"));
    list.push_front(ComplexType(2, 2.2, "two"));
    list.push_front(ComplexType(3, 3.3, "three"));

    auto it = list.begin();
    EXPECT_EQ(it->a_, 3);
    EXPECT_EQ(it->b_, 3.3);
    EXPECT_EQ(it->c_, "three");
    ++it;
    EXPECT_EQ(it->a_, 2);
    EXPECT_EQ(it->b_, 2.2);
    EXPECT_EQ(it->c_, "two");
    ++it;
    EXPECT_EQ(it->a_, 1);
    EXPECT_EQ(it->b_, 1.1);
    EXPECT_EQ(it->c_, "one");
}

// Тест итератора
TEST(ForwardListTest, IteratorTraversal) {
    FixedBlockMemoryResource mr(1024);
    ForwardList<int> list(&mr);

    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }

    int expected = 4;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected);
        --expected;
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}