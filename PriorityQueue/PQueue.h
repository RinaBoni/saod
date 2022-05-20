#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// Класс очереди, но с приоритетом на 200 эл-в.
/// Поэтому если хотите хранить внутри свои структуры, то нужно
/// переопределить оператор меньше
/// </summary>
/// <typeparam name="type"></typeparam>
template<typename type>
class PQueue
{
private:
	
	int count;			//кол-во элементов

	type arr[200];		//массив для хранения

	/// <summary>
	/// находит индекс первого в очереди по приоритету
	/// </summary>
	/// <returns>индекс</returns>
	int find_first();

public:

	/// <summary>
	/// конструктор
	/// </summary>
	PQueue();

	/// <summary>
	/// вставка эл-та в очередь
	/// </summary>
	/// <param name="item">вставляемый эл-т</param>
	void push(const type& item);

	/// <summary>
	/// удаляет эл-т из очереди и возвращает
	/// значение по приоритету
	/// </summary>
	/// <returns> значение по приоритету</returns>
	type pop();

	/// <summary>
	/// возвращает 1й по приоритету эл-т
	/// но не удаляет его
	/// </summary>
	/// <returns>1й по приоритету эл-т</returns>
	type front();

	/// <summary>
	/// очищает очередь
	/// </summary>
	void clear();

	/// <summary>
	/// пустая очередь или нет
	/// </summary>
	/// <returns>true - пустой, false - не пустой<</returns>
	bool empty();

	/// <summary>
	/// возвращает кол-во эл-ов в очереди
	/// </summary>
	/// <returns>кол-во эл-ов в очереди</returns>
	int size();

};

template <typename type>
inline int PQueue<type>::find_first()
{
	//нужно найти минимальный эл-т

	//задаем начальное минимальное значение
	int i_min = 0;

	//проходимся по массиву и находим минимальный эл-т
	for (int i = 0; i < count; i++)
	{
		//Если текущий элемент меньше минимального, то запоминаем индекс
		if (arr[i] < arr[i_min])
		{
			i_min = i;
		}
	}
	//возвращаем индекс
	return i_min;
}


template<typename Type>
inline PQueue<Type>::PQueue()
{
	count = 0;
}


template <typename type>
inline void PQueue<type>::push(const type& item)
{
	if (count < 200)
	{
		arr[count] = item;
		count++;
	}
	else
	{
		throw out_of_range("queue is full");
	}
}

	
template<typename Type>
inline Type PQueue<Type>::pop()
{
	if (count > 0)
	{
		//находим индекс первого в очереди
		int i_min = find_first();

		//мы будем возвращать это значение
		Type min = arr[i_min];

		//теперь удаляем это значение из массива
		arr[i_min] = arr[count - 1];
		count--;

		//возвращаем найденное значение
		return min;
	}
	else
	{
		throw out_of_range("queue is empty");
	}
}


template<typename Type>
inline Type PQueue<Type>::front()
{
	if (count > 0)
	{

		int i_min = find_first();


		return arr[i_min];
	}
	else
		throw out_of_range("queue is empty");
}


template<typename Type>
inline void PQueue<Type>::clear()
{
	count = 0;
}


template<typename Type>
inline bool PQueue<Type>::empty()
{
	return == 0;
}


template<typename Type>
inline int PQueue<Type>::size()
{
	return count;
}