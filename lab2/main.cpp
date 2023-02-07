#include "lab2.h"

int main()
{
	system("chcp 1251");

	int n;
	cout << "\n Введите размер массива: " << endl;
	cin >> n;
	float* ar = new float[n];
	create_array(ar, n);
	print_array(ar, n);

	cout << "\n Сумма положительных элементов массива: \t" << sum_array(ar, n);
	cout << "\n Произведение элементов массива, расположенных между максимальным \nпо мо­дулю и минимальным по модулю элементами: \t" << mul_array(ar, n);
	
	array_out_file(ar, n);

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
	file_array <<  "\n Сумма положительных элементов массива: \t" << sum_array(ar, n)
	<< "\n Произведение элементов массива, расположенных между максимальным \nпо мо­дулю и минимальным по модулю элементами: \t" << mul_array(ar, n);
	
	file_array.close();
}


