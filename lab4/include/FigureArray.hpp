#ifndef FIGUREARRAY_HPP
#define FIGUREARRAY_HPP

#include <memory>
#include <iostream>

// Концепт IsFigure, определяющий, что тип T является фигурой
template <typename T>
concept IsFigure = requires(T a) {
    { a.geometricCenter() } -> std::same_as<typename T::figure_base_type>;
    { static_cast<double>(a) } -> std::same_as<double>;
    { a.clone() } -> std::same_as<T*>;
    { a.print(std::cout) };
    { a.read(std::cin) };
};

template <IsFigure T>
class FigureArray {
public:
    // Конструкторы
    FigureArray();
    explicit FigureArray(size_t capacity);
    FigureArray(const FigureArray<T> &other);
    FigureArray(FigureArray<T> &&other) noexcept;

    // Операторы присваивания
    FigureArray<T>& operator=(const FigureArray<T> &other);
    FigureArray<T>& operator=(FigureArray<T> &&other) noexcept;

    // Оператор доступа по индексу
    T& operator[](size_t index) const;

    // Деструктор
    ~FigureArray();

    // Добавление фигуры
    void add(const std::shared_ptr<T> &figure);

    // Удаление фигуры по индексу
    void remove(size_t index);

    // Вычисление общей площади всех фигур
    double totalArea() const;

    // Вывод всех фигур
    void printAll() const;
    
    size_t size() const;

private:
    std::unique_ptr<std::shared_ptr<T>[]> figures_;  /
    size_t size_;                                    
    size_t capacity_;                                
    // Изменение размера массива
    void resize();
};

#include "../src/FigureArray.tpp"

#endif // FIGUREARRAY_HPP