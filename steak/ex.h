#pragma once
#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;

/// <summary>
/// Добавляет символы строки в стек
/// </summary>
/// <param name="stack">- стек типа char в который добавляются символы</param>
/// <param name="str">- строка, которая разбирается на символы</param>
template<typename type>
void push_to_stack(MyStack<type>& stack, string& str);

/// <summary>
/// Проверяет строку на то палиндром это или нет
/// </summary>
/// <param name="str">- проверяемая строка</param>
/// <returns></returns>
bool check_palidrom(string& str);

/// <summary>
/// Преобразует число из 10-й системы счисления
/// в заданную (до 10)
/// </summary>
/// <param name="value">-число</param>
/// <param name="base">-система счисления</param>
/// <returns>строку с числом</returns>
string number_system(int value, int base);

/////////////////////////////////////////////////////////////

template<typename type>
void push_to_stack(MyStack<type>& stack, string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		stack.push(str[i]);
	}
}


bool check_palidrom(string& str)
{
	MyStack<char> stack;

	push_to_stack(stack, str);

	bool flag = true;

	//проходим по строке и проверяем на символы строки из стека
	for (int i = 0; i < str.size(); i++)
	{
		if (stack.pop() != str[i])
		{
			flag = false;
		}
	}
	return flag;
}


string number_system(int value, int base)
{
	MyStack<int> stack;

	while (value != 0)
	{
		stack.push(value % base);	//делим на основание сис счисления и записываем в стек
		value /= base;
	}
	string str;

	//пока стек не пустой
	while (!stack.empty())
	{
		str += to_string(stack.pop());
	}
	return str;
}