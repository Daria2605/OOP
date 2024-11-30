#ifndef PENTAGON_TPP
#define PENTAGON_TPP

#include "../include/Pentagon.hpp"
#include <cmath>

// Конструктор, принимающий массив точек
template <Numeric T>
Pentagon<T>::Pentagon(const Point<T> (&points)[5]) {
    for (int i = 0; i < 5; ++i) {
        points_[i] = std::make_unique<Point<T>>(points[i]);
    }
    if (!isValidPentagon()) {
        throw std::invalid_argument("Invalid pentagon points");
    }
}

// Конструктор копирования
template <Numeric T>
Pentagon<T>::Pentagon(const Pentagon<T> &other) {
    for (int i = 0; i < 5; ++i) {
        points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
    }
}

// Оператор присваивания копированием
template <Numeric T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T> &other) {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            points_[i] = std::make_unique<Point<T>>(*other.points_[i]);
        }
    }
    return *this;
}

// Оператор присваивания перемещением
template <Numeric T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T> &&other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

// Вычисление геометрического центра
template <Numeric T>
Point<T> Pentagon<T>::geometricCenter() const {
    Point<T> center;
    for (const auto &point : points_) {
        center.x_ += point->x_;
        center.y_ += point->y_;
    }
    center.x_ /= 5;
    center.y_ /= 5;
    return center;
}

// Вычисление площади пятиугольника
template <Numeric T>
Pentagon<T>::operator double() const {

    return 0.0; 

// Сравнение пятиугольников
template <Numeric T>
bool Pentagon<T>::operator==(const Figure<T> &other) const {
    const Pentagon<T> *otherPentagon = dynamic_cast<const Pentagon<T>*>(&other);
    if (!otherPentagon) {
        return false;
    }
    for (int i = 0; i < 5; ++i) {
        if (*points_[i] != *otherPentagon->points_[i]) {
            return false;
        }
    }
    return true;
}

// Вывод пятиугольника в поток
template <Numeric T>
void Pentagon<T>::print(std::ostream& os) const {
    for (const auto &point : points_) {
        os << *point << " ";
    }
}

// Ввод пятиугольника из потока
template <Numeric T>
void Pentagon<T>::read(std::istream& is) {
    for (int i = 0; i < 5; ++i) {
        is >> *points_[i];
    }
    if (!isValidPentagon()) {
        throw std::invalid_argument("Invalid pentagon points");
    }
}

// Проверка валидности пятиугольника
template <Numeric T>
bool Pentagon<T>::isValidPentagon() const {

    return true; 
}

#endif // PENTAGON_TPP