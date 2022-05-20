#pragma once
#include <exception>

/// <summary>
/// Класс простой очереди.
/// Основан на статическом массиве на 200 эл-в
/// </summary>
/// <typeparam name="type"></typeparam>
template<class type>
class Queue
{
private:
	int first;			//указатель на начало очереди 
	int last;			//указатель на конец очереди
	int count;			//кол-во элементов в очереди
	type arr[200];

public:
	
	//инициализируем нулями
	Queue();


	/// <summary>
	/// Вставка элемента в очередь
	/// </summary>
	/// <param name="item">- вставляемый элемент</param>
	void insert(type& item);


	/// <summary>
	/// Возвращает передний элемент и удаляет его из очереди
	/// </summary>
	/// <returns>Передний элемент</returns>
	type delet()
	{
		type buf;

		if (count == 0)
		{
			throw std::invalid_argument("Queue is empty");
		}
		else
		{
			buf = arr[first];
			count--;
			//закольцовываем
			first = (first + 1) % 200;

			return buf;
		}
	}


	/// <summary>
	/// Очищает очередь
	/// </summary>
	void clear();


	/// <summary>
	/// Возвращает размер очереди
	/// </summary>
	/// <returns>размер очереди</returns>
	int lenght();


	/// <summary>
	/// Возвращает размер очереди
	/// </summary>
	/// <returns></returns>
	int size();


	/// <summary>
	/// Проверяет пуста очередь или нет
	/// </summary>
	/// <returns>true - пуста, false - нет</returns>
	bool empty();


	/// <summary>
	/// Возвращает переднее значение очереди, не удаляя его из очереди
	/// </summary>
	/// <returns>первое значение</returns>
	type front()
	{
		return arr[first];
	}
};


template<class type>
inline Queue<type>::Queue()
{
	first = 0;
	last = 0;
	count = 0;
}


template<class type>
inline void Queue<type>::insert(type& item)
{
	//Проверяем не переполнили мы массив
	if (count < 200)
	{
		//вставляем эл-т
		arr[last] = item;

		//и увеличиваем кол-во и указатель
		count++;

		//делаем так, чтобы закольцевать очередь
		last = (last + 1) % 200;
	}
	else
	{
		throw std::invalid_argument("Queue is full");
	}
}


template<class type>
inline void Queue<type>::clear()
{
	count = 0;
	first = 0;
	last = 0;
}


template<class type>
inline int Queue<type>::lenght()
{
	return count;
}


template<class type>
inline int Queue<type>::size()
{
	return count;
}


template<class type>
inline bool Queue<type>::empty()
{
	if (count == 0)
		return true;
	else
		return false;
}