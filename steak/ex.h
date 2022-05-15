#pragma once
#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;

/// <summary>
/// ��������� ������� ������ � ����
/// </summary>
/// <param name="stack">- ���� ���� char � ������� ����������� �������</param>
/// <param name="str">- ������, ������� ����������� �� �������</param>
template<typename type>
void push_to_stack(MyStack<type>& stack, string& str);

/// <summary>
/// ��������� ������ �� �� ��������� ��� ��� ���
/// </summary>
/// <param name="str">- ����������� ������</param>
/// <returns></returns>
bool check_palidrom(string& str);

/// <summary>
/// ����������� ����� �� 10-� ������� ���������
/// � �������� (�� 10)
/// </summary>
/// <param name="value">-�����</param>
/// <param name="base">-������� ���������</param>
/// <returns>������ � ������</returns>
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

	//�������� �� ������ � ��������� �� ������� ������ �� �����
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
		stack.push(value % base);	//����� �� ��������� ��� ��������� � ���������� � ����
		value /= base;
	}
	string str;

	//���� ���� �� ������
	while (!stack.empty())
	{
		str += to_string(stack.pop());
	}
	return str;
}