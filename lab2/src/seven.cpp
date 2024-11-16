#include "../include/seven.h"
#include <iostream>
#include <cstring>


void Seven::resize_arr(const size_t size) 
{
    unsigned char* new_s_array = new unsigned char[size];  // Создаем новый массив нужного размера
    std::memcpy(new_s_array, s_array, size * sizeof(unsigned char));  // Копируем данные из старого массива в новый
    s_size = size;  // Обновляем размер массива
    delete [] s_array;  // Освобождаем память, выделенную под старый массив
    s_array = new_s_array;  // Присваиваем указатель на новый массив
}


// Конструктор по умолчанию
Seven::Seven() 
{
    s_array = new unsigned char;  // Выделяем память под один элемент
    *s_array = {'0'};
    s_size = 1;
}

// Конструктор с параметрами
Seven::Seven(const size_t & n, unsigned char t = '0')
{
    if ((t > 54) || (t < 48)) throw std::invalid_argument("Character not from the working alphabet has been entered");  // Проверяем, что символ находится в диапазоне '0'-'6'
    s_array = new unsigned char [n];
    s_size = n;
    for (int i = 0; i < s_size; ++i) s_array[i] = t;
}

// Конструктор из списка инициализации
Seven::Seven(const std::initializer_list<unsigned char> &t)
{
    s_array = new unsigned char[t.size()];  // Выделяем память под массив размером, равным количеству элементов в списке
    s_size = t.size();  // Устанавливаем размер массива
    int i = t.size() - 1;  // Индекс для заполнения массива с конца
 
    for (unsigned char elem : t)
    {
        if ((elem > 54) || (elem < 48)) throw std::invalid_argument("Character not from the working alphabet has been entered");  // Проверяем, что символ находится в диапазоне '0'-'6'
 
        s_array[i--] = elem;  // Заполняем массив с конца
    }
}

// Конструктор из строки
Seven::Seven(const std::string &t)
{
    s_array = new unsigned char[t.size()];  // Выделяем память под массив размером, равным длине строки
    s_size = t.size();  // Устанавливаем размер массива
    int i = t.size() - 1;  // Индекс для заполнения массива с конца

    for (unsigned char elem : t)
    {
        if ((elem < 48) || (elem > 54)) throw std::invalid_argument("Character not from the working alphabet has been entered");  // Проверяем, что символ находится в диапазоне '0'-'6'
 
        s_array[i--] = elem;  // Заполняем массив с конца
    }
}

// Конструктор копирования
Seven::Seven(const Seven& other)
{
    s_array = new unsigned char[other.s_size];  // Выделяем память под массив размером, равным размеру другого объекта
    std::memcpy(s_array, other.s_array, other.s_size);  // Копируем данные из другого объекта
    s_size = other.s_size;  // Устанавливаем размер массива
}

// Конструктор перемещения
Seven::Seven(Seven&& other) noexcept
{
    s_array = other.s_array;  // Перемещаем указатель на массив
    s_size = other.s_size;  // Перемещаем размер массива
}

// Деструктор
Seven::~Seven() noexcept 
{
    delete [] s_array;  // Освобождаем память, выделенную под массив
}


// Оператор сложения
Seven Seven::operator + (const Seven& other)
{
    size_t size_f, size_s;
    
    if (s_size < other.s_size) 
    {
        size_f = other.s_size;  // Определяем больший размер
        size_s = s_size;  // Определяем меньший размер
    }
    else
    {
        size_f = s_size;  // Определяем больший размер
        size_s = other.s_size;  // Определяем меньший размер
    }
 
    Seven result = Seven(size_f, '0');  // Создаем результат с большим размером, заполненный нулями
    int i_val = 0; 
    int i_position = 0, remnant = 0;
    for (int i = 0; i < size_s; ++i)
    {
        i_val = ((s_array)[i] - 48) + ((other.s_array)[i] - 48) + remnant;  // Складываем цифры и перенос
        remnant = i_val / 7;  // Определяем новый перенос
        i_position = i_val % 7;  // Определяем текущую цифру результата
        result.s_array[i] = i_position + 48;  // Записываем цифру в результат
    }
    
    for (int i = size_s; i < size_f; ++i)
    {
        i_val = (((s_size < other.s_size) ? other.s_array : s_array)[i] - 48) + remnant;  // Складываем цифры и перенос
        remnant = i_val / 7;  // Определяем новый перенос
        i_position = i_val % 7;  // Определяем текущую цифру результата
        result.s_array[i] = i_position + 48;  // Записываем цифру в результат
    }
    
    if (remnant > 0)
    {
        result.resize_arr(size_f + 1);  // Если есть перенос, увеличиваем размер результата
        result.s_array[result.s_size - 1] = remnant + 48;  // Записываем перенос в результат
    }
 
    return result;
}

// Оператор вычитания
Seven Seven::operator - (const Seven& other)
{
    Seven result = *this;  // Создаем копию текущего объекта
 
    if (result < other) throw std::underflow_error("A negative value will be received");  // Проверяем, что результат не будет отрицательным
 
    int remnant = 0;
    int i_val = 0;

    for (int i = 0; i < other.s_size; ++i)
    {
        i_val = (s_array[i] - 48) - (other.s_array[i] - 48) - remnant;  // Вычитаем цифры и заимствование
        result.s_array[i] = ((i_val % 7 + 7) % 7) + 48;  // Определяем текущую цифру результата
        remnant = i_val < 0 ? 1 : 0;  // Определяем новое заимствование
    }

    size_t j = other.s_size;
    while (remnant == 1)
    {
        i_val = (s_array[j] - 48) - remnant;  // Вычитаем цифры и заимствование
        result.s_array[j] = ((i_val % 7 + 7) % 7) + 48;  // Определяем текущую цифру результата
        remnant = i_val < 0 ? 1 : 0;  // Определяем новое заимствование
        j++;
    }
    
    int pop_back = 0;

    for (int i = result.s_size - 1; i > 0; --i)
    {
        if (result.s_array[i] == '0') 
            ++pop_back;  // Считаем количество нулей в конце
        else
            break;
    }

    result.resize_arr(result.s_size - pop_back);  // Уменьшаем размер результата, удаляя нули в конце
    return result;
}

// Оператор присваивания
Seven Seven::operator = (const Seven& other)
{
    resize_arr(other.s_size);  // Изменяем размер массива
    for (int i = 0; i < s_size; ++i)
        s_array[i] = other.s_array[i];  // Копируем данные из другого объекта
        
    return *this;
}

// Оператор сравнения "меньше"
bool Seven::operator < (const Seven& other)
{
    if (s_size < other.s_size)  return true;  // Если размер меньше, то число меньше
 
    if (s_size > other.s_size)  return false;  // Если размер больше, то число больше
 
    for (int i = s_size - 1; i >= 0; --i) 
    {
        if (s_array[i] < other.s_array[i])  return true;  // Сравниваем цифры с конца
 
        if (s_array[i] > other.s_array[i])  return false;
    }
 
    return false;  // Если числа равны
}

// Оператор сравнения "больше"
bool Seven::operator > (const Seven& other)
{
    if (s_size > other.s_size)  return true;  // Если размер больше, то число больше
 
    if (s_size < other.s_size)  return false;  // Если размер меньше, то число меньше
 
    for (int i = s_size - 1; i >= 0; --i) 
    {
        if (s_array[i] > other.s_array[i])  return true;  // Сравниваем цифры с конца
 
        if (s_array[i] < other.s_array[i])  return false;
    }
 
    return false;  // Если числа равны
}

// Оператор сравнения "равно"
bool Seven::operator == (const Seven& other)
{
    if (s_size != other.s_size) return false;  // Если размеры разные, числа не равны
 
    for (int i = s_size - 1; i >= 0; --i)
    {
        if (s_array[i] != other.s_array[i]) return false;  // Сравниваем цифры с конца
    }
 
    return true;  // Если все цифры равны
}

// Метод to_string
std::string Seven::to_string() const
{
    std::string result;
    for (int i = s_size - 1; i >= 0; --i)
        result += s_array[i];  // Добавляем цифры в строку с конца

    return result;
}