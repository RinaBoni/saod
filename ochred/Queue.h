#pragma once
#include <exception>

/// <summary>
/// ����� ������� �������.
/// ������� �� ����������� ������� �� 200 ��-�
/// </summary>
/// <typeparam name="type"></typeparam>
template<class type>
class Queue
{
private:
	int first;			//��������� �� ������ ������� 
	int last;			//��������� �� ����� �������
	int count;			//���-�� ��������� � �������
	type arr[200];

public:
	
	//�������������� ������
	Queue();


	/// <summary>
	/// ������� �������� � �������
	/// </summary>
	/// <param name="item">- ����������� �������</param>
	void insert(type& item);


	/// <summary>
	/// ���������� �������� ������� � ������� ��� �� �������
	/// </summary>
	/// <returns>�������� �������</returns>
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
			//��������������
			first = (first + 1) % 200;

			return buf;
		}
	}


	/// <summary>
	/// ������� �������
	/// </summary>
	void clear();


	/// <summary>
	/// ���������� ������ �������
	/// </summary>
	/// <returns>������ �������</returns>
	int lenght();


	/// <summary>
	/// ���������� ������ �������
	/// </summary>
	/// <returns></returns>
	int size();


	/// <summary>
	/// ��������� ����� ������� ��� ���
	/// </summary>
	/// <returns>true - �����, false - ���</returns>
	bool empty();


	/// <summary>
	/// ���������� �������� �������� �������, �� ������ ��� �� �������
	/// </summary>
	/// <returns>������ ��������</returns>
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
	//��������� �� ����������� �� ������
	if (count < 200)
	{
		//��������� ��-�
		arr[last] = item;

		//� ����������� ���-�� � ���������
		count++;

		//������ ���, ����� ������������ �������
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