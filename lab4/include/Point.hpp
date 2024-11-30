#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <type_traits>

// Концепт Num, определяющий числовые типы
template <typename T>
concept Num = std::is_integral_v<T> || std::is_floating_point_v<T>;

// Структура Point, представляющая точку на плоскости
template <Num T>
struct Point {
    T x_;  // Координата x
    T y_;  // Координата y

    // Конструкторы
    Point() : x_(0), y_(0) {}
    Point(T x, T y) : x_(x), y_(y) {}

    // Операторы сравнения
    bool operator==(const Point<T> &other) const;
    bool operator!=(const Point<T> &other) const;
};

// Перегрузка оператора вывода для Point
template <Num T>
std::ostream &operator<<(std::ostream& os, const Point<T>& point);

// Перегрузка оператора ввода для Point
template <Num T>
std::istream &operator>>(std::istream& is, Point<T>& point);

#include "../src/Point.tpp"  // Включение файла реализации

#endif // POINT_HPP