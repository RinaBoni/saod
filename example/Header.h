#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// ����� ��� �� 200 ���������
/// </summary>
/// <typeparam name="Type"></typeparam>
template<class Type>
class Deque
{
private:

    int const n = 200;

    //������ ������������ ������, ������ ��� �������
    //���� �������� n � �����, ���� ��� �������� ���
    Type* arr = new Type[n];

    //��������� �� ������
    int head = 0;
    //��������� �� �����
    int tail = 0;
    //���-�� ��-� � ����
    int count = 0;

public:

    /// <summary>
    /// ��������� ��-� � ����� ����
    /// </summary>
    /// <typeparam name="Type"></typeparam>
    void push_back(Type item);

    /// <summary>
    /// ��������� ��-� � ������ ����
    /// </summary>
    /// <param name="value"></param>
    void push_front(int value);

    /// <summary>
    /// ������� ��-� � ����� ���� � ���������� ���
    /// </summary>
    /// <returns></returns>
    Type pop_back();

    /// <summary>
    /// ������� ��-� � ������ ���� � ���������� ���
    /// </summary>
    /// <returns></returns>
    Type pop_front();

    /// <summary>
    /// ���������� ��-� � ����� ����, �� ������ ���
    /// </summary>
    /// <returns></returns>
    Type back();

    /// <summary>
    /// ���������� ��-� � ������ ����, �� ������ ���
    /// </summary>
    /// <returns></returns>
    Type front();

    /// <summary>
    /// ���������� ���-�� ��-� � ����
    /// </summary>
    /// <returns></returns>
    int size();

    /// <summary>
    /// �������� �� �� ������ ���� ��� ���
    /// </summary>
    /// <returns>true - ������, false - �� ������</returns>
    bool empty();

    /// <summary>
    /// ������� ���
    /// </summary>
    void clear();

};



template<class Type>
inline void Deque<Type>::push_back(Type item)
{
    if (tail == head && count > 0)
    {
        throw out_of_range("Deque is full!");
    }
    //������� �������� ��-�
    arr[tail] = item;
    count++;
    //� ����� �������� ���������
    tail = (tail + 1) % n;      //��������
}
    
template<class Type>
inline void Deque<Type>::push_front(int value)
{
    //���� ����� � ������ ������ ��������, �� ������ ����������
    if ((head - 1 + n) % n == tail && count > 0)
    {
        throw out_of_range("Deque is full!");
    }
    //������� �������� ���������
    head = (head - 1 + n) % n;  //��������
    //� ������ ����� ���������
    arr[head] = value;
    count++;
}

template<class Type>
inline Type Deque<Type>::pop_back()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        //�������� ��������� �� ���� ��-�
        tail = (tail - 1 + n) % n;
        count--;

        //� ���������� ���
        return arr[tail];
    }

}

template<class Type>
inline Type Deque<Type>::pop_front()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        //�������� ��������� ������
        head = (head + 1) % n;
        count--;

        //���������� ��-�, � �������� ������ ��� ����
        return arr[(head - 1 + n) % n];
    }
}

template<class Type>
inline Type Deque<Type>::back()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        return arr[(tail - 1 + n) % n];
    }

}

template<class Type>
inline Type Deque<Type>::front()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        return arr[head];
    }

}

template<class Type>
inline int Deque<Type>::size()
{
    return count;
}

template<class Type>
inline bool Deque<Type>::empty()
{
    return count == 0;
}

template<class Type>
inline void Deque<Type>::clear()
{
    head = 0;
    tail = 0;
    count = 0;
}