#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <iostream>

class Trapezoid : public Figure {
public:
    Trapezoid(const Point (&points)[4]);
    Trapezoid(const Trapezoid &other);
    Trapezoid(Trapezoid &&other) noexcept;
    Trapezoid& operator=(const Trapezoid &other);
    Trapezoid& operator=(Trapezoid &&other) noexcept;
    ~Trapezoid() override = default;

    Point geometricCenter() const override;
    double area() const override;
    bool operator==(const Figure &other) const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override { return new Trapezoid(*this); }

private:
    Point points_[4];
    bool isValidTrapezoid() const;
};

#endif // TRAPEZOID_HPP