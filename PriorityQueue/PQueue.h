#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// ����� �������, �� � ����������� �� 200 ��-�.
/// ������� ���� ������ ������� ������ ���� ���������, �� �����
/// �������������� �������� ������
/// </summary>
/// <typeparam name="type"></typeparam>
template<typename type>
class PQueue
{
private:
	
	int count;			//���-�� ���������

	type arr[200];		//������ ��� ��������

	/// <summary>
	/// ������� ������ ������� � ������� �� ����������
	/// </summary>
	/// <returns>������</returns>
	int find_first();

public:

	/// <summary>
	/// �����������
	/// </summary>
	PQueue();

	/// <summary>
	/// ������� ��-�� � �������
	/// </summary>
	/// <param name="item">����������� ��-�</param>
	void push(const type& item);

	/// <summary>
	/// ������� ��-� �� ������� � ����������
	/// �������� �� ����������
	/// </summary>
	/// <returns> �������� �� ����������</returns>
	type pop();

	/// <summary>
	/// ���������� 1� �� ���������� ��-�
	/// �� �� ������� ���
	/// </summary>
	/// <returns>1� �� ���������� ��-�</returns>
	type front();

	/// <summary>
	/// ������� �������
	/// </summary>
	void clear();

	/// <summary>
	/// ������ ������� ��� ���
	/// </summary>
	/// <returns>true - ������, false - �� ������<</returns>
	bool empty();

	/// <summary>
	/// ���������� ���-�� ��-�� � �������
	/// </summary>
	/// <returns>���-�� ��-�� � �������</returns>
	int size();

};

template <typename type>
inline int PQueue<type>::find_first()
{
	//����� ����� ����������� ��-�

	//������ ��������� ����������� ��������
	int i_min = 0;

	//���������� �� ������� � ������� ����������� ��-�
	for (int i = 0; i < count; i++)
	{
		//���� ������� ������� ������ ������������, �� ���������� ������
		if (arr[i] < arr[i_min])
		{
			i_min = i;
		}
	}
	//���������� ������
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
		//������� ������ ������� � �������
		int i_min = find_first();

		//�� ����� ���������� ��� ��������
		Type min = arr[i_min];

		//������ ������� ��� �������� �� �������
		arr[i_min] = arr[count - 1];
		count--;

		//���������� ��������� ��������
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