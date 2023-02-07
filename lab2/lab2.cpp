#include "lab2.h"

//наполнение массива значениями от -10 до 10
void create_array(float *array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		array[i] = (- 10) + rand() % (10 - (-10) + 1);
	}
}

//вывод массива на экран
void print_array(float* array, int n)
{
	cout << "\nМассив: \n";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "\t";
	}
}

//сумма всех элементов массива
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

//поиск индекса минимального по модулю элемента
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

//поиск индекса максимального по модулю элемента
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

//умножение
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

//вывод в файл
void array_out_file(float* array, int n)
{
	string path = "array.txt";	//название файла f
	ofstream file_array;			//создаем фаил для записи
	file_array.open(path);		//открываем файл для записи, связываем с именем
	if (!file_array.is_open())	//если не удалось открыть
	{
		cout << "file open error1" << endl;//сообщаем об этом
	}
	else//если открылся
	{
		cout << "file opened successfully" << endl;
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		file_array << array[i] << "\t";	//записываем массив в файл
	}
	file_array.close();			//закрываем файл
}