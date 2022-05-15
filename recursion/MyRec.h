#pragma once
//13. ¬ычислить произведение элементов одномерного массива

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//заполнение массива
void FellRandom(int* arr, int size);

//ѕроизведение эл-тов массива с помощи итераций
long long iteration(int* arr, int size);

//произведение эл-тов массива с помощи рекурсии
long long rec(int* arr, int size);

//вывод массива на экран
void ToScreen(int* arr, int size);

//вывод массива в файл
void ToFile(int* arr, int size, ofstream& write);

///////////////////////////////////////////////////////////////////////////////


//заполнение массива
void FellRandom(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 - 5;
	}
}


//ѕроизведение эл-тов массива с помощи итераций
long long iteration(int* arr, int size)
{
	long long itog = arr[0];

	for (int i = 1; i < size; i++)		//проходим массив
	{
		itog *= arr[i];					//перемножаем
	}
	return itog;
}


//произведение эл-тов массива с помощи рекурсии
long long rec(int* arr, int size)
{
	if (size == 0)			//условие выхода
	{
		return arr[size];
	}
	return arr[size] * rec(arr, size - 1);	//нынешний элемент умножаем на следующий(но следующий в обратном пор€дке)
}


//вывод массива на экран
void ToScreen(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}


//вывод массива в файл
void ToFile(int* arr, int size, ofstream& write)
{
	for (int i = 0; i < size; i++)
	{
		write << arr[i] << " ";
	}
	write << "\n";
}