#include <iostream>
#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

int main()
{
    // Определение точек для трапеции
    Point<double> points_trapezoid[4] = {
        Point<double>(1, 1), Point<double>(5, 1), Point<double>(4, 3), Point<double>(2, 3) 
    };

    // Определение точек для пятиугольника
    Point<double> points_pentagon[5] = {
        Point<double>(0, 0), Point<double>(2, 0), Point<double>(3, 2), Point<double>(1, 4), Point<double>(-1, 2) 
    };

    // Определение точек для ромба
    Point<double> points_rhombus[4] = {
        Point<double>(0, 0), Point<double>(3, 1), Point<double>(0, 2), Point<double>(-3, 1) 
    };

    // Создание объектов трапеции, пятиугольника и ромба
    Trapezoid<double> trapezoid(points_trapezoid);
    Pentagon<double> pentagon(points_pentagon);
    Rhombus<double> rhombus(points_rhombus);

    // Создание умных указателей на объекты трапеции, пятиугольника и ромба
    auto trapezoid_ptr = std::make_shared<Trapezoid<double>>(points_trapezoid);
    auto pentagon_ptr = std::make_shared<Pentagon<double>>(points_pentagon);
    auto rhombus_ptr = std::make_shared<Rhombus<double>>(points_rhombus);

    // Вывод информации о трапеции
    std::cout << "Trapezoid Information: " << std::endl;
    std::cout << trapezoid << std::endl;
    std::cout << "Area: " << static_cast<double>(trapezoid) << std::endl;
    std::cout << "Geometric Center: " << trapezoid.geometricCenter() << std::endl;
    
    // Вывод информации о пятиугольнике
    std::cout << "\nPentagon Information: " << std::endl;
    std::cout << pentagon << std::endl;
    std::cout << "Area: " << static_cast<double>(pentagon) << std::endl;
    std::cout << "Geometric Center: " << pentagon.geometricCenter() << std::endl;
    
    // Вывод информации о ромбе
    std::cout << "\nRhombus Information: " << std::endl;
    std::cout << rhombus << std::endl;
    std::cout << "Area: " << static_cast<double>(rhombus) << std::endl;
    std::cout << "Geometric Center: " << rhombus.geometricCenter() << std::endl;

    // Создание массива фигур и добавление в него трапеции, пятиугольника и ромба
    FigureArray<Figure<double>> figureArray;
    figureArray.add(trapezoid_ptr);
    figureArray.add(pentagon_ptr);
    figureArray.add(rhombus_ptr);

    // Вывод информации о фигурах в массиве
    std::cout << "\nFigures in Array: " << std::endl;
    for (size_t i = 0; i < figureArray.size(); ++i) {
        std::cout << figureArray[i] << std::endl;
    }

    return 0;
}