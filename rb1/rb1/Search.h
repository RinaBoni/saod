#pragma once
#include <exception>
#include <vector>
#include <fstream>
#include <time.h>
/// <summary>
/// ���������������� ����� �� �����
/// </summary>
/// <typeparam name="T"> ��� ������� � �������� �������� </typeparam>
/// <param name="arr"> - ������, � ������� ����� ������������� ����� </param >
/// <param name="size"> - ������ ������� </param>
/// <param name="key"> - �������� ��������, ������� ����� �������� </param >
/// <returns>������ �������� � �������</returns>
template<typename T>
int search_sequential(std::vector<T>& arr, T key);

/// <summary>
/// �������� ����� � �������, ������ ������ ���� �������������� ������������,
/// ����� ����� ����� �������� ����������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"> - ������, � ������� ����� �����</param>
/// <param name="size"> - ������ �������</param>
/// <param name="key"> - ���� ��� ������(��������, ������ ������)</param >
/// <returns> ������ �������� ��������</returns>
template<typename T>
int search_binary(std::vector<T>& arr, T key);

/// <summary>
/// ��������� ������ �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">��� ������������ �������</param>
template<typename T>
void fill_hand_vector(std::vector<T>& arr);

/// <summary>
/// ��������� ������ ���������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">��� ������������ �������</param>
template<typename T>
void fill_rand_vector(std::vector<T>& arr);

/// <summary>
/// ������� ������ �� �����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">������, ��������� �� �����</param>
template<typename T>
void print_vector(const std::vector<T>&arr);

/// <summary>
/// ������� ������ � ��������� ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">-������, ��������� �� �����</param>
/// <param name="f">-�������� ����������, ���� ������ ���� ������</param >
template<typename T>
void printTofile_vector(const std::vector<T>& arr, std::ofstream& f);

///////////////////////////////////////////////////////////////////////
//////////////////
template<typename T>
int search_sequential(std::vector<T>& arr, T key) ///���������������� ����� �� �����
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == key) //������ ������� � ������
		{
			return i;
		}
	}
	throw std::invalid_argument("�� ������� ����� �������!\n");
}

template<typename T>
int search_binary(std::vector<T>& arr, T key) ///�������� �����
{
	int left = 0, right = arr.size() - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2; //������� ������ ������������ ��������
								  //� ������� ����� ������� �������, � ����������� �� ���� � ����� ������� ����� ������� ��������
			if (arr[mid] >= key)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
	}
	if (arr[left] != key)
	{
		throw std::invalid_argument("�� ������� ����� ������ �������, �������� ������ ��� �� ������������!\n");
	}
	return left;
}

template<typename T>
void fill_hand_vector(std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cin >> arr[i];
	}
}

template<typename T>
void fill_rand_vector(std::vector<T>& arr)
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = (rand() % 100) / (rand() % 10 + 1);
	}
}

template<typename T>
void print_vector(const std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
		if (i > 0 && i % 9 == 0)
		{
			std::cout << "\n";
		}
	}
}

template<typename T>
void printTofile_vector(const std::vector<T>&arr, std::ofstream & f)
{
	for (int i = 0; i < arr.size(); i++)
	{
		f << arr[i] << " ";
		if (i > 0 && i % 9 == 0)
		{
			f << "\n";
		}
	}
}