#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <exception>
#include "MyStack.h"

typedef long long ll;

using namespace std;

/// <summary>
/// ����������� �����������, ������� ������ � ��������� ����
/// ����������� Ctrl+Z + Enter
/// </summary>
class calc_postfix
{
private:
	
	MyStack<ll> stack_number;		//���� � �������

	vector<char> arr_operation;		//������ � ����������

	ll op_left;						//����� �������
	ll op_right;						//������ �������

	/// <summary>
	/// ��������� ������ � ��������� ���� � ������� � 
	/// ������ � ����������
	/// </summary>
	void read()
	{
		string str_number;
		char symbol;
		string str;

		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
		{
			//���� ��� �����, �� ��������� � ������
			if (str[i] >= '0' && str[i] <= '9')
			{
				str_number += str[i];
			}
			else
			{
				if (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				{
					//���� ������, �� ��������� � ����� � ���������� � ����
					//����� ������� ������
					int number = stoi(str_number);
					stack_number.push(number);
					str_number.clear();
				}

				//����� ���������� �������� � ������
				if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
				{
					arr_operation.push_back(str[i]);
				}
			}
		}
	}

	/// <summary>
	/// ���������� �������� ����� ����������
	/// </summary>
	/// <param name="i" - ������ �������� � �������></param>
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
				throw invalid_argument("������� �� ����!");
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
	///  ����� ������ ������, ��������� �� ����� � ��������
	/// + - * / ^
	/// �������� ���� ����������� Ctrl+Z + Enter
	/// </summary>
	/// <returns> ����� ���� long long </returns>
	ll calculate()
	{
		read();

		//���������� �� ��������� � �������
		for (int i = 0; i < arr_operation.size(); i++)
		{
			//��������� ������ �� ����
			if (!stack_number.empty())
			{
				//����� ������ �������
				op_right = stack_number.pop();

				//����� ��������� ������ �� ����
				if (!stack_number.empty())
				{
					//����� ����� �������
					op_left = stack_number.pop();

					//���������
					operation(i);
				}
				else throw invalid_argument("������� ����� ��������, �� ������� ����� ��� ����������");
			}
			else
				throw invalid_argument("������� ����� ��������, �� ������� ����� ��� ����������");
		}
		return stack_number.peek();
	}
};