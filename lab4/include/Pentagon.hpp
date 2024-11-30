#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>


template <typename T>
concept Num = std::is_arithmetic_v<T>;

template <Num T>
class Pentagon : public Figure<T> {
public:
    using figure_base_type = T;

    // Конструкторы
    Pentagon() = default;
    Pentagon(const Point<T> (&points)[5]);
    Pentagon(const Pentagon<T> &other);

    // Операторы присваивания
    Pentagon& operator=(const Pentagon<T> &other);
    Pentagon& operator=(Pentagon<T> &&other) noexcept;

    // Переопределение чисто виртуальных методов базового класса
    Point<T> geometricCenter() const override;
    operator double() const override;
    bool operator==(const Figure<T> &other) const override;

    // Клонирование
    virtual Figure<T>* clone() const override {
        return new Pentagon(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::unique_ptr<Point<T>> points_[5];  // Указатели на точки пятиугольника

    bool isValidPentagon() const;
};

#include "../src/Pentagon.tpp"

#endif // PENTAGON_HPP