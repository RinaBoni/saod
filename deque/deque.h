#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// класс дек на 200 эл-ов
/// </summary>
/// <typeparam name="type"></typeparam>
template<class type>
class Deque
{
private:

	//кол-во эл-ов
	int const n = 200;

	//создаем динамический массив
	type* arr = new type[n];

	//указатель на голову
	int head = 0;

	//указатель на конец
	int tail = 0;

	//кол-во эл-ов в деке
	int count = 0;

public:

	/// <summary>
	/// добавл€ет элемент в конец дека
	/// </summary>
	/// <param name="item">элемент</param>
	void push_back(type item);

	/// <summary>
	/// добавл€ет элемент в начало деко
	/// </summary>
	/// <param name="value">элемент</param>
	void push_front(type item);

	/// <summary>
	/// удал€ет элемент с конца дека и возвращает его
	/// </summary>
	/// <returns>элемент с конца дека</returns>
	type pop_back();

	/// <summary>
	/// удал€ет элемент с нацала дека и возвращает его
	/// </summary>
	/// <returns>элемент с нацала дека</returns>
	type pop_front();

	/// <summary>
	/// возврацает эл-т с конца дека не удал€€ его
	/// </summary>
	/// <returns> эл-т с конца дека</returns>
	type back();

	/// <summary>
	/// возврацает эл-т с начала дека не удал€€ его
	/// </summary>
	/// <returns>эл-т с начала дека </returns>
	type front();

	/// <summary>
	/// возвращает кло-во эл-ов в деке
	/// </summary>
	/// <returns>кло-во эл-ов в деке</returns>
	int size();

	/// <summary>
	/// проверка на пустоту
	/// </summary>
	/// <returns>true - дек пустой, false - не пустой</returns>
	bool empty();

	/// <summary>
	/// очистка дека
	/// </summary>
	void clear();
};

template<class type>
inline void Deque<type>::push_back(type item)
{
	//проверка дека на полноту
	if (tail == head && count > 0)
	{
		throw out_of_range("Deque is full");
	}

	//добавл€ем элемент
	arr[tail] = item;
	
	//увеличиваем дек
	count++;

	//сдвигаем указатель и кольцуем
	tail = (tail + 1) % n;
}


template<class type>
inline void Deque<type>::push_front(type item)
{
	//усли хвост и голова сход€тс€, кидаем исключение
	if ((head - 1 + n) % n == tail && count > 0)
	{
		throw out_of_range("Deque is full");
	}

	//сдвигаем указатель и кольцуем
	head = (head - 1 + n) % n;

	//добавл€ем элемент
	arr[head] = item;
	
	//увеличиваем дек
	count++;
}


template<class type>
inline type Deque<type>::pop_back()
{
	//проверка дека на пустоту
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//сдвигаем указатель на этот элемент
		tail = (tail - 1 + n) % n;

		//уменьшаем
		count--;

		//возращаем элемент
		return arr[tail];
	}
}


template<class type>
inline type Deque<type>::pop_front()
{
	//провер€ем дек на пустоту
	if (count == 0)
	{
		throw out_of_range("Deque is empty");

	}
	else
	{
		//сдвигаем указатель вправо
		head = (head + 1) % n;

		//уменьшаем
		count--;

		//возвращаем элемент, с к-го только что ушли
		return arr[(head - 1 + n) % n];
	}
}


template<class type>
inline type Deque<type>::back()
{
	//провер€ем дек на пустоту
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//возвращаем конец
		return arr[(tail - 1 + n) % n];
	}
}



template<class type>
inline type Deque<type>::front()
{
	//проверка на пустоту
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//возвращаем начало
		return arr[head];
	}
}



template<class type>
inline int Deque<type>::size()
{
	//возвращаем размер дека
	return count;
}


template<class type>
inline bool Deque<type>::empty()
{
	return count == 0;
}



template<class type>
inline void Deque<type>::clear()
{
	//занул€ем все
	head = 0;
	tail = 0;
	count = 0;
}