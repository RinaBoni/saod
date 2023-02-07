#pragma once

#include <iostream>
#include <vector>

using namespace std;


/// <summary>
///				Алгоритм быстрой сортировки массива класса vector
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, который можно отсортировать	  - </param>
/// <param name="first"> -	индекс начала сортировки	- </param>
/// <param name="last"> -	индекс конца сортировки		-</param>
template<typename type>
void QuickSorting(vector<type>& arr, int first, int last);


/// <summary>
///								Пузырьковая сортировка
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void BubbleSorting(vector<type>& arr);


/// <summary>
///								Сортировка выбором
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void SelectSorting(vector<type>& arr);

/// <summary>
///								Сортировка вставками
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void InsertionSorting(vector<type>& arr);

/// <summary>
///								Сортировка Шелла
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void ShellSorting(vector<type>& arr);


//////////////////////////////////////////////////////////////////////

/// <summary>
///				Алгоритм быстрой сортировки массива класса vector
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, который можно отсортировать	  - </param>
/// <param name="first"> -	индекс начала сортировки	- </param>
/// <param name="last"> -	индекс конца сортировки		-</param>
template<typename type>
void QuickSorting(vector<type>& arr, int first, int last)
{
	if (first < last)
	{
		//указываем на левый и правый индексы массива
		int left = first;
		int right = last;
		//находим значение, к-е лежит в центре, причем так, чтобы не получилось переполнение
		int mid = arr[left + (right - left) / 2];

		do
		{
			//идем по левой стороне массива и ищем
			//эл-т, к-й больше серединного значения
			while (arr[left] < mid)
			{
				left++;
			}

			//идем по правой стороне массива и ищем
			//эл-т, к-й меньше серединного значения
			while (arr[right] > mid)
			{
				right--;
			}

			//как только мы нашли эти эл-ты, левый и правые индексы не поменялись местами
			//меняем эл-ты местами
			if (left <= right)
			{
				type buffer = arr[left];
				arr[left] = arr[right];
				arr[right] = buffer;

				//и передвегаем индексы
				left++;
				right--;
			}
		}
		while (left < right);

		//теперь снова вызываем нашу ф-ю для левой и правой частей массива
		QuickSorting(arr, first, right);	//левая
		QuickSorting(arr, left, last);		//правая
	}
	else
	{
		return;
	}

















}


/// <summary>
///								Пузырьковая сортировка
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void BubbleSorting(vector<type>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			//если следующий эл-т меньше текущего, то меняем их местами
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


/// <summary>
///								Сортировка выбором
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void SelectSorting(vector<type>& arr)
{
	//внешний цикл, в к-ои ставим уже нужные значения
	for (int i = 0; i < arr.size() - 1; i++)
	{
		//устанавливаем начальный индекс минимального значения
		int i_min = i;

		//внутренний, в к=ом будем искать минимум
		for (int j = i + 1; j < arr.size(); j++)
		{
			//находим минимум в этой части массива
			if (arr[j] < arr[i_min])
			{
				i_min = j;
			}
		}

		//меняем эти значения местами
		swap(arr[i], arr[i_min]);
	}
}


/// <summary>
///								Сортировка вставками
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void InsertionSorting(vector<type>& arr)
{
	//начинаем со 2-го эл-та, тк 1-й эл-т типо считается уже отсортированным массивом, он crazy
	for (int i = 1; i < arr.size; i++)
	{
		int buf = arr[i];//буфер
		int j = i - 1;
		
		while (j >= 0 && arr[j] > buf)
		{
			//смещаем эл-ты в право
			arr[j + 1] = arr[j];

			//ставим эл-т в нужное место
			arr[j] = buf;

			j--;
		}
	}
}


/// <summary>
///								Сортировка Шелла
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	массив, к-й нужно отсортировать		- </param>
template<typename type>
void ShellSorting(vector<type>& arr)
{
	int j;
	int step;	//шаг, к-м будем делить массив на части

	for (step = arr.size() / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arr.size(); i++)
		{
			type buf = arr[i];

			for (j = i; j >= step; j -= step)
			{
				//тут обычные вставки
				if (buf < arr[j - step])
				{
					arr[j] = arr[j - step];
				}

				else
				{
					break;
				}
			}

			arr[j] = buf;
		}
	}

}