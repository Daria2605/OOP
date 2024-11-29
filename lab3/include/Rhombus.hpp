#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <iostream>

class Rhombus : public Figure {
public:
    Rhombus(const Point (&points)[4]);
    Rhombus(const Rhombus &other);
    Rhombus(Rhombus &&other) noexcept;
    Rhombus& operator=(const Rhombus &other);
    Rhombus& operator=(Rhombus &&other) noexcept;
    ~Rhombus() override = default;

    Point geometricCenter() const override;
    double area() const override;
    bool operator==(const Figure &other) const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override { return new Rhombus(*this); }

private:
    Point points_[4];
    bool isValidRhombus() const;
    double distance(const Point &p1, const Point &p2) const;
};

#endif // RHOMBUS_HPP