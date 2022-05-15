//13. Вычислить произведение элементов одномерного массива

#include <iostream>
#include <exception>
#include <chrono>
#include <iomanip>

#include "MyRec.h"

int main()
{
	system("chcp 1251");

    ofstream write("Result.txt");       //файл с результатом

    int size = 10;

    int* arr = new int[size];           //выделяем память под массив

    FellRandom(arr, size);              //заполняем массив




    //////////////////////////////// Рекурсия \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 

    long long itog;                     //переменная в которую запишем значение произведения

    auto start = chrono::high_resolution_clock::now();    //время начала работы 
    itog = rec(arr, size - 1);        //вызываем рекурсию                    
    auto end = chrono::high_resolution_clock::now();      //конец работы ф-ии  

    chrono::duration<float>  duration = end - start;    //Считаем время выполнения рекурсии

    ///////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




    //////////////////////////////// Итерация \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 


    long long itog1;

    auto start_iteration = chrono::high_resolution_clock::now();    //время начала работы 
    itog1 = iteration(arr, size);
    auto end_iteration = chrono::high_resolution_clock::now();      //конец работы ф-ии

    chrono::duration<float>  duration_iteration = end_iteration - start_iteration;  //снова считае время, но для итерации

    ///////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




     //////////////////////////////// Вывод \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
    
    cout << "\n\nВычислить произведение элементов одномерного массива" << endl << endl;
    cout << "Массив:\n";
    ToScreen(arr, size);

    write << "\n\nВычислить произведение элементов одномерного массива\n";
    write << "Массив:\n";
    ToFile(arr, size, write);
    
    
    cout << "\nПроизведение всех элементов:" << itog << endl << endl;                   //выводим итог на экран
    write << "\nПроизведение всех элементов:" << itog << endl << endl;                  //итог в файл  
     
     //вывод времени рекурсии
    cout << setprecision(10);
    cout << "\nВремя выполнения рекурсии:" << duration.count() << endl << endl;
    write << setprecision(10);
    write << "\nВремя выполнения рекурсии:" << duration.count() << endl << endl;

    //вывод времени итерации
    cout << setprecision(10);
    cout << "\nВремя выполнения итерационнного метода:" << duration_iteration.count() << endl << endl;
    write << setprecision(10);
    write << "\nВремя выполнения итерационнного метода:" << duration_iteration.count() << endl << endl;





}