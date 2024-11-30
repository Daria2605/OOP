#include "Trapezoid.hpp"
#include <cmath>

// Конструктор, принимающий массив точек
template <Num T>
Trapezoid<T>::Trapezoid(const Point<T> (&points)[4]) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = std::make_unique<Point<T>>(points[i]);
    }
    if (!isValidTrapezoid()) {
        throw std::invalid_argument("Invalid trapezoid points");
    }
}

// Конструктор копирования
template <Num T>
Trapezoid<T>::Trapezoid(const Trapezoid<T> &other) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
    }
}

// Оператор присваивания копированием
template <Num T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T> &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
        }
    }
    return *this;
}

// Оператор присваивания перемещением
template <Num T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid<T> &&other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

// Вычисление геометрического центра
template <Num T>
Point<T> Trapezoid<T>::geometricCenter() const {
    Point<T> center;
    for (const auto &point : points_) {
        center.x_ += point->x_;
        center.y_ += point->y_;
    }
    center.x_ /= 4;
    center.y_ /= 4;
    return center;
}

// Вычисление площади трапеции
template <Num T>
Trapezoid<T>::operator double() const {
    // Реализация вычисления площади трапеции
    // ...
    return 0.0;  // Заглушка
}

// Сравнение трапеций
template <Num T>
bool Trapezoid<T>::operator==(const Figure<T> &other) const {
    const Trapezoid<T> *otherTrapezoid = dynamic_cast<const Trapezoid<T>*>(&other);
    if (!otherTrapezoid) {
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (*points_[i] != *otherTrapezoid->points_[i]) {
            return false;
        }
    }
    return true;
}

// Вывод трапеции в поток
template <Num T>
void Trapezoid<T>::print(std::ostream& os) const {
    for (const auto &point : points_) {
        os << *point << " ";
    }
}

// Ввод трапеции из потока
template <Num T>
void Trapezoid<T>::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> *points_[i];
    }
    if (!isValidTrapezoid()) {
        throw std::invalid_argument("Invalid trapezoid points");
    }
}

// Проверка валидности трапеции
template <Num T>
bool Trapezoid<T>::isValidTrapezoid() const {
    // Реализация проверки валидности трапеции
    // ...
    return true;  