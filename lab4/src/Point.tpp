#ifndef POINT_TPP
#define POINT_TPP

#include "../include/Point.hpp"

// Реализация оператора сравнения на равенство
template <Num T>
bool Point<T>::operator==(const Point<T> &other) const {
    return x_ == other.x_ && y_ == other.y_;
}

// Реализация оператора сравнения на неравенство
template <Num T>
bool Point<T>::operator!=(const Point<T> &other) const {
    return !(*this == other);
}

// Реализация оператора вывода
template <Num T>
std::ostream &operator<<(std::ostream& os, const Point<T>& point) {
    os << "(" << point.x_ << ", " << point.y_ << ")";
    return os;
}

// Реализация оператора ввода
template <Num T>
std::istream &operator>>(std::istream& is, Point<T>& point) {
    is >> point.x_ >> point.y_;
    return is;
}

#endif // POINT_TPP