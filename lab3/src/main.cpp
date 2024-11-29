#include <iostream>
#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

int main()
{
    Point points_trapezoid[4] = { Point(0, 0), Point(1, 4), Point(2, 4), Point(6, 0) };
    Point points_pentagon[5] = { Point(0, 2), Point(2, 4), Point(4, 2), Point(3, 0), Point(1, 0) };
    Point points_rhombus[4] = { Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0) };

    Trapezoid trapezoid(points_trapezoid);
    Pentagon pentagon(points_pentagon);
    Rhombus rhombus(points_rhombus);

    std::cout << "Trapezoid Information: " << std::endl;
    std::cout << trapezoid << std::endl;
    std::cout << "Area: " << trapezoid.area() << std::endl;
    std::cout << "Geometric Center: " << trapezoid.geometricCenter() << std::endl;
    
    std::cout << "\nPentagon Information: " << std::endl;
    std::cout << pentagon << std::endl;
    std::cout << "Area: " << pentagon.area() << std::endl;
    std::cout << "Geometric Center: " << pentagon.geometricCenter() << std::endl;
    
    std::cout << "\nRhombus Information: " << std::endl;
    std::cout << rhombus << std::endl;
    std::cout << "Area: " << rhombus.area() << std::endl;
    std::cout << "Geometric Center: " << rhombus.geometricCenter() << std::endl;

    // Создание массива фигур
    FigureArray figureArray(3);
    figureArray.add(&trapezoid);
    figureArray.add(&pentagon);
    figureArray.add(&rhombus);

    std::cout << "\nTotal Area of All Figures: " << figureArray.totalArea() << std::endl;

    std::cout << "\nPrinting All Figures: " << std::endl;
    figureArray.printAll();

    return 0;
}