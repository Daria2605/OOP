#pragma once
#include <string>
#include <cstring>
 
class Seven
{
    private:
        unsigned char *s_array;  // Указатель на массив символов
        std::size_t s_size;
        void resize_arr(const size_t);  // Приватный метод для изменения размера массива

    public:
        // Конструкторы
        Seven();  // Конструктор по умолчанию
        Seven(const std::size_t &, unsigned char);  // Конструктор с параметрами
        Seven(const std::initializer_list<unsigned char> &);  // Конструктор из списка инициализации
        Seven(const std::string &);  // Конструктор из строки
        Seven(const Seven&);  // Конструктор копирования
        Seven(Seven&& other) noexcept;  // Конструктор перемещения
        
        ~Seven() noexcept;

        // Операторы
        Seven operator + (const Seven&);
        Seven operator - (const Seven&);
        Seven operator = (const Seven&);
        bool operator < (const Seven&);
        bool operator > (const Seven&);
        bool operator == (const Seven&);

        // Методы
        std::string to_string() const;  // Метод для преобразования числа в строковое представление
};