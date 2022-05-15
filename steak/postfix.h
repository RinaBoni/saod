#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <exception>
#include "MyStack.h"

typedef long long ll;

using namespace std;

/// <summary>
/// ѕостфиксный калькул€тор, вводите строку и закончите ввод
/// комбинацией Ctrl+Z + Enter
/// </summary>
class calc_postfix
{
private:
	
	MyStack<ll> stack_number;		//стек с числами

	vector<char> arr_operation;		//массив с операндами

	ll op_left;						//левый операнд
	ll op_right;						//правый операнд

	/// <summary>
	/// считывает строку и заполн€ет стек с чмслами и 
	/// массив с операци€ми
	/// </summary>
	void read()
	{
		string str_number;
		char symbol;
		string str;

		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
		{
			//если это цифра, то добавл€ем в строку
			if (str[i] >= '0' && str[i] <= '9')
			{
				str_number += str[i];
			}
			else
			{
				if (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				{
					//если символ, то переводим в число и записываем в стек
					//после очищаем строку
					int number = stoi(str_number);
					stack_number.push(number);
					str_number.clear();
				}

				//после записываем операцию в массив
				if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
				{
					arr_operation.push_back(str[i]);
				}
			}
		}
	}

	/// <summary>
	/// ѕроизводим операцию между операндами
	/// </summary>
	/// <param name="i" - индекс операции в массиве></param>
	void operation(int i)
	{
		switch (arr_operation[i])
		{
		case '+':
			stack_number.push(op_left + op_right);
			break;

		case '-':
			stack_number.push(op_left - op_right);
			break;

		case '*':
			stack_number.push(op_left * op_right);
			break;

		case '/':
			if (op_right == 0)
				throw invalid_argument("ƒеление на ноль!");
			else
				stack_number.push(op_left / op_right);
			break;

		case '^':
			stack_number.push(pow(op_left, op_right));
			break;

		default:
			break;
		}
			
	}
public:
	
	/// <summary>
	///  нужно ввести строку, состо€щую из чисел и операций
	/// + - * / ^
	/// окончите ввод комбинацией Ctrl+Z + Enter
	/// </summary>
	/// <returns> „исло типа long long </returns>
	ll calculate()
	{
		read();

		//проходимс€ по опираци€м и считаем
		for (int i = 0; i < arr_operation.size(); i++)
		{
			//провер€ем пустой ли стек
			if (!stack_number.empty())
			{
				//Ѕерем правый операнд
				op_right = stack_number.pop();

				//снова провер€ем пустой ли стек
				if (!stack_number.empty())
				{
					//берем левый операнд
					op_left = stack_number.pop();

					//считываем
					operation(i);
				}
				else throw invalid_argument("—лишком много операций, не хватает чисел дл€ вычислений");
			}
			else
				throw invalid_argument("—лишком много операций, не хватает чисел дл€ вычислений");
		}
		return stack_number.peek();
	}
};