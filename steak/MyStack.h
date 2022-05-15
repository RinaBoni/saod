#pragma once
#include <exception>

/// <summary>
///Стек на основе статического массива
/// </summary>
/// <typeparam name="t"></typeparam>
template <typename t>
class MyStack
{
private:
	
	int capacity = 200;

	t arr[200];

	int top;	//указатель на верхний эл-т

public:

	/// <summary>
	/// 
	/// </summary>
	MyStack()
	{
		top = -1;
	}


	/// <summary>
	/// добавляем значение в стек
	/// </summary>
	/// <param name="value-значение"></param>
	void push(t value)
	{
		if (top == capacity - 1)
		{
			top = -1;		//циклим
		}
		top++;
		arr[top] = value;
	}


	/// <summary>
	///  Возвращает верхнее значение стека
	/// </summary>
	/// <returns>Верхнее значение стек</returns>
	t peek()
	{
		if (top > -1)
			return arr[top];
		else
			throw std::invalid_argument("Stack is empty!");
	}


	/// <summary>
	/// удаление верхнего эл-та из стека, также возвращает этот эл-т
	/// </summary>
	/// <returns>верх эл-т стека</returns>
	t pop()
	{
		if (top > -1)
		{
			top--;
			return arr[top + 1];
		}
	}


	/// <summary>
	/// очистка стека
	/// </summary>
	void clear()
	{
		return top + 1;
	}


	/// <summary>
	/// разиер стека
	/// </summary>
	/// <returns></returns>
	int size()
	{
		return top + 1;
	}


	/// <summary>
	/// проверяет пустой стек или нет
	/// </summary>
	/// <returns>true - если пустой, faulse - еслт нет</returns>
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