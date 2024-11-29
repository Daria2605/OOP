#include "FigureArray.hpp"
#include <iostream>
#include <utility>

FigureArray::FigureArray(size_t capacity)
    : figures_(new Figure*[capacity]), size_(0), capacity_(capacity) {}

FigureArray::FigureArray(const FigureArray &other)
    : figures_(new Figure*[other.capacity_]), size_(other.size_), capacity_(other.capacity_)
{
    for (size_t i = 0; i < other.size_; ++i) {
        figures_[i] = other.figures_[i]->clone();
    }
}

FigureArray& FigureArray::operator=(const FigureArray &other)
{
    if (this == &other) {
        return *this;
    }

    FigureArray temp(other);
    swap(temp);

    return *this;
}

FigureArray::FigureArray(FigureArray &&other) noexcept
    : figures_(other.figures_), size_(other.size_), capacity_(other.capacity_)
{
    other.figures_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

FigureArray& FigureArray::operator=(FigureArray &&other) noexcept
{
    if (this != &other) {
        clear();
        figures_ = other.figures_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.figures_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

FigureArray::~FigureArray()
{
    clear();
    delete[] figures_;
}

void FigureArray::add(Figure *figure)
{
    if (figure == nullptr) {
        std::cerr << "Cannot add a null figure." << std::endl;
        return;
    }

    if (size_ >= capacity_) {
        std::cerr << "Array is full. Cannot add more figures." << std::endl;
        return;
    }

    figures_[size_++] = figure->clone();
}

void FigureArray::remove(size_t index)
{
    if (index >= size_) {
        std::cerr << "Invalid index." << std::endl;
        return;
    }
    delete figures_[index];
    for (size_t i = index; i < size_ - 1; ++i) {
        figures_[i] = figures_[i + 1];
    }
    --size_;
}

double FigureArray::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size_; ++i) {
        if (figures_[i] != nullptr) {
            total += figures_[i]->area();
        }
    }
    return total;
}

void FigureArray::printAll() const
{
    for (size_t i = 0; i < size_; ++i) {
        if (figures_[i]) { 
            std::cout << *figures_[i] << std::endl;
        }
    }
}

size_t FigureArray::size() const
{
    return size_;
}

void FigureArray::resize()
{
    size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;

    Figure **newData = new Figure*[newCapacity];
    for (size_t i = 0; i < size_; ++i) {
        newData[i] = figures_[i];
    }

    for (size_t i = size_; i < newCapacity; ++i) {
        newData[i] = nullptr;
    }
    delete[] figures_;

    figures_ = newData;
    capacity_ = newCapacity;
}

void FigureArray::clear()
{
    for (size_t i = 0; i < size_; ++i) {
        delete figures_[i];
    }
    size_ = 0;
}

void FigureArray::swap(FigureArray &other) noexcept
{
    std::swap(figures_, other.figures_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}