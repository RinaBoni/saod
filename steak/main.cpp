﻿//1.Проверить является ли строка полидромом.
//Строка может содержать и числа, и буквы
// 
//2.Переобразовать целое десятичное число в 
//число с другим основанием (2, 3, ..., 9)
//
//3.Реализовать постфиксный калькулятор


#include <iostream>
#include "MyStack.h"
#include "ex.h"
#include "postfix.h"

using namespace std;

int main()
{
    system("chcp 1251");



    ///////палиндром\\\\\\\

    string str;
    cout << "\nВведите строку: ";
    cin >> str;

    if (check_palidrom(str))
    {
        cout << "\nСтрока является полиндромом\n";
    }
    else
    {
        cout << "\nСтрока не является полиндромом\n";
    }

    //////////\\\\\\\\



    ///////перевод в сис счисления\\\\\\\

    int value;
    cout << "\nВведите число: ";
    cin >> value;

    int base;
    cout << "\nВведите основание системы счисления: ";
    cin >> base;

    cout << "\nВот что получилось: " << number_system(value, base);

    //////////\\\\\\\\



    ///////постфиксный калькулятор\\\\\\\

    calc_postfix calc;

    cout << "\n\nВведите выражение для постфиксного калькулятора: ";
    cin.ignore();

    ll a = calc.calculate();

    cout << "\nОтвет: " << a;

    //////////\\\\\\\
    
}