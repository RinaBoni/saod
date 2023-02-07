#include "lab2.h"

//���������� ������� ���������� �� -10 �� 10
void create_array(float *array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		array[i] = (- 10) + rand() % (10 - (-10) + 1);
	}
}

//����� ������� �� �����
void print_array(float* array, int n)
{
	cout << "\n������: \n";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "\t";
	}
}

//����� ���� ��������� �������
float sum_array(float* array, int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > 0)
			sum =+ array[i];
	}
	return sum;
}

//����� ������� ������������ �� ������ ��������
int imin_array(float* array, int n)
{
	float min = 0; 
	int imin = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(array[i]) < min)
		{
			min = array[i];
			imin = i;
		}
	}
	return imin;
}

//����� ������� ������������� �� ������ ��������
int imax_array(float* array, int n)
{
	float max = 0;
	int imax = 0;
	for (int i = 0; i < n; i++)
	{
			if (abs(array[i]) > max)
			{
				max = array[i];
				imax = i;
			}
	}
	return imax;
}

//���������
float mul_array(float* array, int n)
{
	float mul = 1;
	for (int i = 0; i < n; i++)
	{
		if ((imin_array(array, n) >= i) && (imax_array(array, n) <= i))
		{
			mul = array[i] * mul;
		}
	}
}

/*int imax_array(float* array, int n)
{
	float max = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}*/

/*void sort_array(float* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] > array[i + 1])
		{
			array[i] =
		}
	}
}*/

//����� � ����
void array_out_file(float* array, int n)
{
	string path = "array.txt";	//�������� ����� f
	ofstream file_array;			//������� ���� ��� ������
	file_array.open(path);		//��������� ���� ��� ������, ��������� � ������
	if (!file_array.is_open())	//���� �� ������� �������
	{
		cout << "file open error1" << endl;//�������� �� ����
	}
	else//���� ��������
	{
		cout << "file opened successfully" << endl;
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		file_array << array[i] << "\t";	//���������� ������ � ����
	}
	file_array.close();			//��������� ����
}