#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Point.hpp"
#include <iostream>


template <typename T>
concept Num = std::is_arithmetic_v<T>;

template <Num T>
class Figure {
public:
    virtual ~Figure() noexcept = default;

    // Сравнивает две фигуры на равенство
    virtual bool operator==(const Figure<T> &other) const = 0;

    // Клонирует фигуру
    virtual Figure* clone() const = 0;

    // Возвращает геометрический центр фигуры
    virtual Point<T> geometricCenter() const = 0;

    // Преобразует фигуру в double (например, площадь)
    virtual operator double() const = 0;


    // Выводит информацию о фигуре в поток
    virtual void print(std::ostream& os) const = 0;

    // Считывает информацию о фигуре из потока
    virtual void read(std::istream& is) = 0;
};

// Перегрузка оператора вывода для фигуры
template <Num T>
std::ostream& operator<<(std::ostream& os, const Figure<T> &fig) {
    fig.print(os);
    return os;
}

// Перегрузка оператора ввода для фигуры
template <Num T>
std::istream& operator>>(std::istream& is, Figure<T> &fig) {
    fig.read(is);
    return is;
}

#include "../src/Figure.tpp"

#endif // FIGURE_HPP