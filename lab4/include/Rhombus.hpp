#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>

template <typename T>
concept Num = std::is_arithmetic_v<T>;

template <Num T>
class Rhombus : public Figure<T> {
public:
    using figure_base_type = T;
    
    // Конструкторы
    Rhombus() = default;
    Rhombus(const Point<T> (&points)[4]);
    Rhombus(const Rhombus<T> &other);

    // Операторы присваивания
    Rhombus &operator=(const Rhombus<T> &other);
    Rhombus &operator=(Rhombus<T> &&other) noexcept;

    // Переопределение чисто виртуальных методов базового класса
    Point<T> geometricCenter() const override;
    double distance(const Point<T> &p1, const Point<T> &p2) const;
    operator double() const override;
    bool operator==(const Figure<T> &other) const override;

    // Клонирование
    virtual Figure<T>* clone() const override {
        return new Rhombus(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::unique_ptr<Point<T>> points_[4];  // Указатели на точки ромба

    bool isValidRhombus() const;
};

#include "../src/Rhombus.tpp"

#endif // RHOMBUS_HPP