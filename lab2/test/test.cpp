#include <gtest/gtest.h>
#include "../include/seven.h"

//Тест конструктора по умолчанию, из списка инициализации, операторы +, =, >, <
TEST(test1, basic_test_set1)
{
    Seven number1, number2;
    

    ASSERT_TRUE(number1.to_string() == "0" && number2.to_string() == "0");

    number1 = {'2', '3'};
    number2 = {'1', '2'};
    number2 = number2 + number1;
    EXPECT_FALSE(number1 == number2);
    EXPECT_FALSE(number1 > number2);
    EXPECT_TRUE(number1 < number2);
}

//Тест конструктора из списка инициализации
TEST(test2, basic_test_set2)
{
    Seven number1{'2', '1', '2'};
    Seven number2{'3', '4'};
    Seven number3{'1', '0', '3'};

    ASSERT_TRUE(number1.to_string() == "212" && number2.to_string() == "34");

    number1 = number1 - number2; // 212 - 34 = 145
    EXPECT_TRUE(number1.to_string() == "145");

    number3 = number3 + number2; // 103 + 34 = 140
    EXPECT_TRUE(number3.to_string() == "140");
}

//из списка инициализации и оператор - на границах
TEST(test3, basic_test_set3)
{
    Seven number1{'1', '0', '0'};
    Seven number2{'1'};
    Seven number3 = number1 - number2;

    EXPECT_TRUE(number3.to_string() == "66");

    number1 = {'3'};
    EXPECT_THROW(number2 - number1, std::underflow_error);
}

//из списка инициализации и оператор + на границах
TEST(test4, basic_test_set4)
{
    Seven number1{'6', '6', '6'};
    Seven number2{'1'};
    Seven number3 = number1 + number2;
    
    EXPECT_TRUE(number3.to_string() == "1000");

    number3 = number2 + number1;
    EXPECT_TRUE(number3.to_string() == "1000");
}


// Тесты для конструктора с размером и символом
TEST(test5, basic_test_set5) {
    Seven num(4, '1');
    EXPECT_TRUE(num.to_string() == "1111");
}

// Тесты для конструктора копирования
TEST(test6, basic_test_set6) {
    Seven num1("123");
    Seven num2(num1);
    EXPECT_TRUE(num1.to_string() == num2.to_string());
}

//Тесты для конструктора из строки
TEST(test7, basic_test_set7) {
    Seven num1("615");
    EXPECT_TRUE(num1.to_string() == "615");
}

//Тесты для равенства
TEST(test8, base_test_set8) {
    Seven num1("5612");
    Seven num2("5612");
    Seven num3("2341");

    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 == num3);
}