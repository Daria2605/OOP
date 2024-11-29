#include "gtest/gtest.h"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

// Тесты для класса Trapezoid
TEST(TrapezoidTest, ConstructorCopy) {
    Point points[4] = { Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3) };
    Trapezoid t1(points);
    Trapezoid t2 = t1;
    EXPECT_EQ(t1, t2);
}

TEST(TrapezoidTest, ConstructorMove) {
    Point points[4] = { Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3) };
    Trapezoid t1(points);
    Trapezoid t2 = std::move(t1);
    EXPECT_NEAR(t2.area(), 12.0, 1e-6);
}

TEST(TrapezoidTest, Area) {
    Point points[4] = { Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3) };
    Trapezoid t(points);
    double area = t.area();
    EXPECT_NEAR(area, 12.0, 1e-6);
}

TEST(TrapezoidTest, GeometricCenter) {
    Point points[4] = { Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3) };
    Trapezoid t(points);
    Point center = t.geometricCenter();
    EXPECT_NEAR(center.x_, 2.5, 1e-6);
    EXPECT_NEAR(center.y_, 1.5, 1e-6);
}

TEST(TrapezoidTest, EqualityOperator) {
    Point points1[4] = { Point(0, 0), Point(5, 0), Point(4, 3), Point(1, 3) };
    Trapezoid t1(points1);
    Trapezoid t2(points1);
    EXPECT_TRUE(t1 == t2);
}

// Тесты для класса Pentagon
TEST(PentagonTest, ConstructorCopy) {
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p1(points);
    Pentagon p2 = p1;
    EXPECT_EQ(p1, p2);
}

TEST(PentagonTest, ConstructorMove) {
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p1(points);
    Pentagon p2 = std::move(p1);
    EXPECT_NEAR(p2.area(), 5.5, 1e-6);
}

TEST(PentagonTest, Area) {
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p(points);
    double area = p.area();
    EXPECT_NEAR(area, 5.5, 1e-6);
}

TEST(PentagonTest, GeometricCenter) {
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p(points);
    Point center = p.geometricCenter();
    EXPECT_NEAR(center.x_, 2.3, 1e-6);
    EXPECT_NEAR(center.y_, 2.0, 1e-6);
}

TEST(PentagonTest, EqualityOperator) {
    Point points1[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p1(points1);
    Pentagon p2(points1);
    EXPECT_TRUE(p1 == p2);
}

// Тесты для класса Rhombus
TEST(RhombusTest, ConstructorCopy) {
    Point points[4] = { Point(0, 0), Point(3, 4), Point(0, 8), Point(-3, 4) };
    Rhombus r1(points);
    Rhombus r2 = r1;
    EXPECT_EQ(r1, r2);
}

TEST(RhombusTest, ConstructorMove) {
    Point points[4] = { Point(0, 0), Point(3, 4), Point(0, 8), Point(-3, 4) };
    Rhombus r1(points);
    Rhombus r2 = std::move(r1);
    EXPECT_NEAR(r2.area(), 24.0, 1e-6);
}

TEST(RhombusTest, Area) {
    Point points[4] = { Point(0, 0), Point(3, 4), Point(0, 8), Point(-3, 4) };
    Rhombus r(points);
    double area = r.area();
    EXPECT_NEAR(area, 24.0, 1e-6);
}

TEST(RhombusTest, GeometricCenter) {
    Point points[4] = { Point(0, 0), Point(3, 4), Point(0, 8), Point(-3, 4) };
    Rhombus r(points);
    Point center = r.geometricCenter();
    EXPECT_NEAR(center.x_, 0.0, 1e-6);
    EXPECT_NEAR(center.y_, 4.0, 1e-6);
}

TEST(RhombusTest, EqualityOperator) {
    Point points1[4] = { Point(0, 0), Point(3, 4), Point(0, 8), Point(-3, 4) };
    Rhombus r1(points1);
    Rhombus r2(points1);
    EXPECT_TRUE(r1 == r2);
}

// Тесты для класса FigureArray
TEST(FigureArrayTest, AddAndTotalArea) {
    FigureArray array(10);
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon* p = new Pentagon(points);
    array.add(p);
    EXPECT_NEAR(array.totalArea(), p->area(), 1e-6);
    delete p;
}

TEST(FigureArrayTest, Remove) {
    FigureArray array(10);
    Point points[5] = { Point(1, 1), Point(3, 1), Point(4, 2), Point(2.5, 4), Point(1, 2) };
    Pentagon p(points);
    array.add(&p);
    array.remove(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, Size) {
    FigureArray array(10);
    EXPECT_EQ(array.size(), 0);
}