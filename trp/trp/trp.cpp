// trp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// Заполнение вектора вручную
/// </summary>
/// <param name="arr">- заполняемый вектор</param>
void fill_vector(vector<int>& arr);


/// <summary>
/// Возвращает вектор с разменом суммы данными номиналами, с помощью жадного алгоритма
/// </summary>
/// <param name="arr">- массив номиналов</param>
/// <param name="kyp">- сумма, которую нужно разменять</param>
/// <returns></returns>
vector<int> jaba(vector<int>& arr, int kyp);

/// <summary>
/// Вывод массива на экран
/// </summary>
/// <param name="arr"></param>
void print_vector(vector<int>& arr);



int main()
{
    system("chcp 1251");
    
    //Считываем сумму которую нужно разменять
    int kyp;
    cout << "Введите номинал купюры: ";
    cin >> kyp;

    //Считываем кол-во  номиналов, которыми будлем разменивать
    int num_coins;
    cout << "Введите количество разных номиналов: ";
    cin >> num_coins;

    //Считываем сами номиналы
    cout << "Введите монеты для размена: ";
    vector<int> coins(num_coins);
    fill_vector(coins);

    cout << "Размен: ";
    //Получаем массив с разменом  из номиналов
    vector<int> razmen = jaba(coins, kyp);

    //выводим эти номиналы на экран
    print_vector(razmen);
   



}

void fill_vector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

vector<int> jaba(vector<int>& arr, int kyp)
{
    sort(arr.begin(), arr.end());

    int i = arr.size() - 1;

    vector<int> razmen;

    while (i >= 0 || kyp != 0)
    {
        if (kyp - arr[i] >= 0)
        {
            razmen.push_back(arr[i]);
            kyp = kyp - arr[i];
        }
        else
        {
            i--;
        }
    }

    return razmen;
}


void print_vector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}