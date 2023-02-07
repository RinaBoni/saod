#pragma once

#include <iostream>
#include<vector>
#include <time.h>

using namespace std;

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
template<typename T>
void CreatArr(vector<T>& arr);


/// <summary>
/// 
/// </summary>
/// <typeparam name="T"> -	любой вектор	- </typeparam>
/// <param name="arr"> -	вектор	- </param>
template<typename T>
void print_arr(vector<T>& arr);





/// <summary>
/// 
/// </summary>
/// <typeparam name="T"> -	любой вектор	- </typeparam>
/// <param name="arr"> -	вектор	- </param>
template<typename T>
void print_arr(vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
        if (i > 0 && i % 14 == 0)
        {
            cout << "\n";
        }
    }
}



/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
template<typename T>
void CreatArr(vector<T>& arr)
{
    arr.clear();        //очищаям
    arr.resize(5000);   //перезадаем размер
    
                        //заполнение
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }
}
  