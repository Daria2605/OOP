#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>


template <typename T>
concept Num = std::is_arithmetic_v<T>;

template <Num T>
class Trapezoid : public Figure<T> {
public:
    using figure_base_type = T;
    
    // Конструкторы
    Trapezoid() = default;
    Trapezoid(const Point<T> (&points)[4]);
    Trapezoid(const Trapezoid<T> &other);

    // Операторы присваивания
    Trapezoid& operator=(const Trapezoid<T> &other);
    Trapezoid& operator=(Trapezoid<T> &&other) noexcept;
    
    // Переопределение чисто виртуальных методов базового класса
    Point<T> geometricCenter() const override;
    operator double() const override;
    bool operator==(const Figure<T> &other) const override;

    // Клонирование
    virtual Figure<T>* clone() const override {
        return new Trapezoid(*this);
    }

    // Вывод и ввод
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::unique_ptr<Point<T>> points_[4];  // Указатели на точки трапеции

    // Проверка валидности трапеции
    bool isValidTrapezoid() const;
};

#include "../src/Trapezoid.tpp"

#endif // TRAPEZOID_HPP