#pragma once
#include <exception>

/// <summary>
///���� �� ������ ������������ �������
/// </summary>
/// <typeparam name="t"></typeparam>
template <typename t>
class MyStack
{
private:
	
	int capacity = 200;

	t arr[200];

	int top;	//��������� �� ������� ��-�

public:

	/// <summary>
	/// 
	/// </summary>
	MyStack()
	{
		top = -1;
	}


	/// <summary>
	/// ��������� �������� � ����
	/// </summary>
	/// <param name="value-��������"></param>
	void push(t value)
	{
		if (top == capacity - 1)
		{
			top = -1;		//������
		}
		top++;
		arr[top] = value;
	}


	/// <summary>
	///  ���������� ������� �������� �����
	/// </summary>
	/// <returns>������� �������� ����</returns>
	t peek()
	{
		if (top > -1)
			return arr[top];
		else
			throw std::invalid_argument("Stack is empty!");
	}


	/// <summary>
	/// �������� �������� ��-�� �� �����, ����� ���������� ���� ��-�
	/// </summary>
	/// <returns>���� ��-� �����</returns>
	t pop()
	{
		if (top > -1)
		{
			top--;
			return arr[top + 1];
		}
	}


	/// <summary>
	/// ������� �����
	/// </summary>
	void clear()
	{
		return top + 1;
	}


	/// <summary>
	/// ������ �����
	/// </summary>
	/// <returns></returns>
	int size()
	{
		return top + 1;
	}


	/// <summary>
	/// ��������� ������ ���� ��� ���
	/// </summary>
	/// <returns>true - ���� ������, faulse - ���� ���</returns>
	bool empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};