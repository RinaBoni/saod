#pragma once
//13. ��������� ������������ ��������� ����������� �������

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//���������� �������
void FellRandom(int* arr, int size);

//������������ ��-��� ������� � ������ ��������
long long iteration(int* arr, int size);

//������������ ��-��� ������� � ������ ��������
long long rec(int* arr, int size);

//����� ������� �� �����
void ToScreen(int* arr, int size);

//����� ������� � ����
void ToFile(int* arr, int size, ofstream& write);

///////////////////////////////////////////////////////////////////////////////


//���������� �������
void FellRandom(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 - 5;
	}
}


//������������ ��-��� ������� � ������ ��������
long long iteration(int* arr, int size)
{
	long long itog = arr[0];

	for (int i = 1; i < size; i++)		//�������� ������
	{
		itog *= arr[i];					//�����������
	}
	return itog;
}


//������������ ��-��� ������� � ������ ��������
long long rec(int* arr, int size)
{
	if (size == 0)			//������� ������
	{
		return arr[size];
	}
	return arr[size] * rec(arr, size - 1);	//�������� ������� �������� �� ���������(�� ��������� � �������� �������)
}


//����� ������� �� �����
void ToScreen(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}


//����� ������� � ����
void ToFile(int* arr, int size, ofstream& write)
{
	for (int i = 0; i < size; i++)
	{
		write << arr[i] << " ";
	}
	write << "\n";
}