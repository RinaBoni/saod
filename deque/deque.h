#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// ����� ��� �� 200 ��-��
/// </summary>
/// <typeparam name="type"></typeparam>
template<class type>
class Deque
{
private:

	//���-�� ��-��
	int const n = 200;

	//������� ������������ ������
	type* arr = new type[n];

	//��������� �� ������
	int head = 0;

	//��������� �� �����
	int tail = 0;

	//���-�� ��-�� � ����
	int count = 0;

public:

	/// <summary>
	/// ��������� ������� � ����� ����
	/// </summary>
	/// <param name="item">�������</param>
	void push_back(type item);

	/// <summary>
	/// ��������� ������� � ������ ����
	/// </summary>
	/// <param name="value">�������</param>
	void push_front(type item);

	/// <summary>
	/// ������� ������� � ����� ���� � ���������� ���
	/// </summary>
	/// <returns>������� � ����� ����</returns>
	type pop_back();

	/// <summary>
	/// ������� ������� � ������ ���� � ���������� ���
	/// </summary>
	/// <returns>������� � ������ ����</returns>
	type pop_front();

	/// <summary>
	/// ���������� ��-� � ����� ���� �� ������ ���
	/// </summary>
	/// <returns> ��-� � ����� ����</returns>
	type back();

	/// <summary>
	/// ���������� ��-� � ������ ���� �� ������ ���
	/// </summary>
	/// <returns>��-� � ������ ���� </returns>
	type front();

	/// <summary>
	/// ���������� ���-�� ��-�� � ����
	/// </summary>
	/// <returns>���-�� ��-�� � ����</returns>
	int size();

	/// <summary>
	/// �������� �� �������
	/// </summary>
	/// <returns>true - ��� ������, false - �� ������</returns>
	bool empty();

	/// <summary>
	/// ������� ����
	/// </summary>
	void clear();
};

template<class type>
inline void Deque<type>::push_back(type item)
{
	//�������� ���� �� �������
	if (tail == head && count > 0)
	{
		throw out_of_range("Deque is full");
	}

	//��������� �������
	arr[tail] = item;
	
	//����������� ���
	count++;

	//�������� ��������� � ��������
	tail = (tail + 1) % n;
}


template<class type>
inline void Deque<type>::push_front(type item)
{
	//���� ����� � ������ ��������, ������ ����������
	if ((head - 1 + n) % n == tail && count > 0)
	{
		throw out_of_range("Deque is full");
	}

	//�������� ��������� � ��������
	head = (head - 1 + n) % n;

	//��������� �������
	arr[head] = item;
	
	//����������� ���
	count++;
}


template<class type>
inline type Deque<type>::pop_back()
{
	//�������� ���� �� �������
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//�������� ��������� �� ���� �������
		tail = (tail - 1 + n) % n;

		//���������
		count--;

		//��������� �������
		return arr[tail];
	}
}


template<class type>
inline type Deque<type>::pop_front()
{
	//��������� ��� �� �������
	if (count == 0)
	{
		throw out_of_range("Deque is empty");

	}
	else
	{
		//�������� ��������� ������
		head = (head + 1) % n;

		//���������
		count--;

		//���������� �������, � �-�� ������ ��� ����
		return arr[(head - 1 + n) % n];
	}
}


template<class type>
inline type Deque<type>::back()
{
	//��������� ��� �� �������
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//���������� �����
		return arr[(tail - 1 + n) % n];
	}
}



template<class type>
inline type Deque<type>::front()
{
	//�������� �� �������
	if (count == 0)
	{
		throw out_of_range("Deque is empty");
	}
	else
	{
		//���������� ������
		return arr[head];
	}
}



template<class type>
inline int Deque<type>::size()
{
	//���������� ������ ����
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
	//�������� ���
	head = 0;
	tail = 0;
	count = 0;
}