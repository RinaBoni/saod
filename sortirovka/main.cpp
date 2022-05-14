//пкзыриковая сортировка 
//сортировка выбором
//сортировка вставками
//быстрая сортировка
//сортировка шелла
//пузырьковая сортировка

#include <iostream>
#include <chrono>   //для засечения времени
#include <time.h>   //для рандома
#include <fstream>  //для файла
#include "msort.h"  //сортировки
#include "MyAdditionally.h"     //мой доп

using namespace std;

int main()
{
    system("chcp 1251");        //руссификация
    srand(time(NULL));          //рандом
    ofstream f("result.txt");   //файл

    vector<int>arr(5000);       //массив

    cout << "Проверка идет на массиве размером в 5000 элементов и после каждой сортировки\nмассив заполняется новыми значениями\n";
    f << "Проверка идет на массиве размером в 5000 элементов и после каждой сортировки\nмассив заполняется новыми значениями\n";


    //заполнение массива
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }


    //Замеряем врямя быстрой сортировки
    auto start = chrono::high_resolution_clock::now();
    QuickSorting(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;   //вычитаем начало из конца

    cout << "Время быстрой сортировки: " << count.count() << "\n";
    f << "Время быстрой сортировки: " << count.count() << "\n";



    //Перезаполняем массив
    CreatArr(arr);

    //Замер сортировки шелла
    auto start = chrono::high_resolution_clock::now();
    ShellSorting(arr);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;   //вычитаем начало из конца

    cout << "Время сортировки Шелла: " << count.count() << "\n";
    f << "Время сортировки Шелла: " << count.count() << "\n";




    //Перезаполняем массив
    CreatArr(arr);

    //Замер сортировки вставками
    auto start = chrono::high_resolution_clock::now();
    InsertionSorting(arr);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;   //вычитаем начало из конца

    cout << "Время сортировки вставками: " << count.count() << "\n";
    f << "Время сортировки вставками: " << count.count() << "\n";




    //Перезаполняем массив
    CreatArr(arr);

    //Замер сортировки выбором
    auto start = chrono::high_resolution_clock::now();
    SelectSorting(arr);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;   //вычитаем начало из конца

    cout << "Время сортировки выбором: " << count.count() << "\n";
    f << "Время сортировки выбором: " << count.count() << "\n";




    //Перезаполняем массив
    CreatArr(arr);

    //Замер сортировки пузырьком
    auto start = chrono::high_resolution_clock::now();
    BubbleSorting(arr);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;   //вычитаем начало из конца

    cout << "Время сортировки пузырьком: " << count.count() << "\n";
    f << "Время сортировки пузырьком: " << count.count() << "\n";
}