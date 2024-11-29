#ifndef FIGUREARRAY_HPP
#define FIGUREARRAY_HPP

#include "Figure.hpp"
#include <iostream>

class FigureArray {
public:
    FigureArray(size_t capacity);
    FigureArray(const FigureArray &other);
    FigureArray(FigureArray &&other) noexcept;
    FigureArray& operator=(const FigureArray &other);
    FigureArray& operator=(FigureArray &&other) noexcept;
    ~FigureArray();

    void add(Figure *figure);
    void remove(size_t index);
    double totalArea() const;
    void printAll() const;
    size_t size() const;
    void resize();

private:
    Figure **figures_;
    size_t size_;
    size_t capacity_;
    void clear();
    void swap(FigureArray &other) noexcept;
};

#endif // FIGUREARRAY_HPP