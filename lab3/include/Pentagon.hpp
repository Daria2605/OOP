#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <iostream>

class Pentagon : public Figure {
public:
    Pentagon(const Point (&points)[5]);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon& operator=(const Pentagon &other);
    Pentagon& operator=(Pentagon &&other) noexcept;
    ~Pentagon() override = default;

    Point geometricCenter() const override;
    double area() const override;
    bool operator==(const Figure &other) const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override { return new Pentagon(*this); }

private:
    Point points_[5];
    bool isValidPentagon() const;
};

#endif // PENTAGON_HPP