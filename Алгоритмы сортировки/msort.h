#pragma once

#include <iostream>
#include <vector>

using namespace std;


/// <summary>
///				�������� ������� ���������� ������� ������ vector
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, ������� ����� �������������	  - </param>
/// <param name="first"> -	������ ������ ����������	- </param>
/// <param name="last"> -	������ ����� ����������		-</param>
template<typename type>
void QuickSorting(vector<type>& arr, int first, int last);


/// <summary>
///								����������� ����������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void BubbleSorting(vector<type>& arr);


/// <summary>
///								���������� �������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void SelectSorting(vector<type>& arr);

/// <summary>
///								���������� ���������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void InsertionSorting(vector<type>& arr);

/// <summary>
///								���������� �����
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void ShellSorting(vector<type>& arr);


//////////////////////////////////////////////////////////////////////

/// <summary>
///				�������� ������� ���������� ������� ������ vector
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, ������� ����� �������������	  - </param>
/// <param name="first"> -	������ ������ ����������	- </param>
/// <param name="last"> -	������ ����� ����������		-</param>
template<typename type>
void QuickSorting(vector<type>& arr, int first, int last)
{
	if (first < last)
	{
		//��������� �� ����� � ������ ������� �������
		int left = first;
		int right = last;
		//������� ��������, �-� ����� � ������, ������ ���, ����� �� ���������� ������������
		int mid = arr[left + (right - left) / 2];

		do
		{
			//���� �� ����� ������� ������� � ����
			//��-�, �-� ������ ����������� ��������
			while (arr[left] < mid)
			{
				left++;
			}

			//���� �� ������ ������� ������� � ����
			//��-�, �-� ������ ����������� ��������
			while (arr[right] > mid)
			{
				right--;
			}

			//��� ������ �� ����� ��� ��-��, ����� � ������ ������� �� ���������� �������
			//������ ��-�� �������
			if (left <= right)
			{
				type buffer = arr[left];
				arr[left] = arr[right];
				arr[right] = buffer;

				//� ����������� �������
				left++;
				right--;
			}
		}
		while (left < right);

		//������ ����� �������� ���� �-� ��� ����� � ������ ������ �������
		QuickSorting(arr, first, right);	//�����
		QuickSorting(arr, left, last);		//������
	}
	else
	{
		return;
	}

















}


/// <summary>
///								����������� ����������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void BubbleSorting(vector<type>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			//���� ��������� ��-� ������ ��������, �� ������ �� �������
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


/// <summary>
///								���������� �������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void SelectSorting(vector<type>& arr)
{
	//������� ����, � �-�� ������ ��� ������ ��������
	for (int i = 0; i < arr.size() - 1; i++)
	{
		//������������� ��������� ������ ������������ ��������
		int i_min = i;

		//����������, � �=�� ����� ������ �������
		for (int j = i + 1; j < arr.size(); j++)
		{
			//������� ������� � ���� ����� �������
			if (arr[j] < arr[i_min])
			{
				i_min = j;
			}
		}

		//������ ��� �������� �������
		swap(arr[i], arr[i_min]);
	}
}


/// <summary>
///								���������� ���������
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void InsertionSorting(vector<type>& arr)
{
	//�������� �� 2-�� ��-��, �� 1-� ��-� ���� ��������� ��� ��������������� ��������, �� crazy
	for (int i = 1; i < arr.size; i++)
	{
		int buf = arr[i];//�����
		int j = i - 1;
		
		while (j >= 0 && arr[j] > buf)
		{
			//������� ��-�� � �����
			arr[j + 1] = arr[j];

			//������ ��-� � ������ �����
			arr[j] = buf;

			j--;
		}
	}
}


/// <summary>
///								���������� �����
/// </summary>
/// <typeparam name="type"> -	int, double, char	- </typeparam>
/// <param name="arr"> -	������, �-� ����� �������������		- </param>
template<typename type>
void ShellSorting(vector<type>& arr)
{
	int j;
	int step;	//���, �-� ����� ������ ������ �� �����

	for (step = arr.size() / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arr.size(); i++)
		{
			type buf = arr[i];

			for (j = i; j >= step; j -= step)
			{
				//��� ������� �������
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