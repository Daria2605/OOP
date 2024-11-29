#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Point.hpp"
#include <iostream>

class Figure {
public:
    virtual ~Figure() noexcept = default;

    virtual Point geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual bool operator==(const Figure &other) const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual Figure* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure &fig) {
        fig.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure &fig) {
        fig.read(is);
        return is;
    }
};

#endif // FIGURE_HPP