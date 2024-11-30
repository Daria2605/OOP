#ifndef FIGURE_TPP
#define FIGURE_TPP

#include "../include/Figure.hpp"

// Перегрузка оператора вывода для фигуры
template <Num T>
std::ostream& operator<<(std::ostream& os, const Figure<T> &fig)
{
    fig.print(os);
    return os;
}

// Перегрузка оператора ввода для фигуры
template <Num T>
std::istream& operator>>(std::istream& is, Figure<T> &fig)
{
    fig.read(is);
    return is;
}

#endif // FIGURE_TPP