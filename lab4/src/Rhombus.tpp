#include "Rhombus.hpp"
#include <cmath>

// Конструктор, принимающий массив точек
template <Num T>
Rhombus<T>::Rhombus(const Point<T> (&points)[4]) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = std::make_unique<Point<T>>(points[i]);
    }
    if (!isValidRhombus()) {
        throw std::invalid_argument("Invalid rhombus points");
    }
}

// Конструктор копирования
template <Num T>
Rhombus<T>::Rhombus(const Rhombus<T> &other) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
    }
}

// Оператор присваивания копированием
template <Num T>
Rhombus<T>& Rhombus<T>::operator=(const Rhombus<T> &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
        }
    }
    return *this;
}

// Оператор присваивания перемещением
template <Num T>
Rhombus<T>& Rhombus<T>::operator=(Rhombus<T> &&other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

// Вычисление геометрического центра
template <Num T>
Point<T> Rhombus<T>::geometricCenter() const {
    Point<T> center;
    for (const auto &point : points_) {
        center.x_ += point->x_;
        center.y_ += point->y_;
    }
    center.x_ /= 4;
    center.y_ /= 4;
    return center;
}

// Вычисление расстояния между двумя точками
template <Num T>
double Rhombus<T>::distance(const Point<T> &p1, const Point<T> &p2) const {
    return std::sqrt(std::pow(p1.x_ - p2.x_, 2) + std::pow(p1.y_ - p2.y_, 2));
}

// Вычисление площади ромба
template <Num T>
Rhombus<T>::operator double() const {
    // Реализация вычисления площади ромба
    // ...
    return 0.0;  // Заглушка
}

// Сравнение ромбов
template <Num T>
bool Rhombus<T>::operator==(const Figure<T> &other) const {
    const Rhombus<T> *otherRhombus = dynamic_cast<const Rhombus<T>*>(&other);
    if (!otherRhombus) {
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (*points_[i] != *otherRhombus->points_[i]) {
            return false;
        }
    }
    return true;
}

// Вывод ромба в поток
template <Num T>
void Rhombus<T>::print(std::ostream& os) const {
    for (const auto &point : points_) {
        os << *point << " ";
    }
}

// Ввод ромба из потока
template <Num T>
void Rhombus<T>::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> *points_[i];
    }
    if (!isValidRhombus()) {
        throw std::invalid_argument("Invalid rhombus points");
    }
}

// Проверка валидности ромба
template <Num T>
bool Rhombus<T>::isValidRhombus() const {
    // Реализация проверки валидности ромба
    // ...
    return true;  // Заглушка
}