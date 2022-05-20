#include <iostream>
#include <deque>
#include <fstream>
#include "deque.h"

int main()
{
    system("chcp 1251");
    
    ofstream f("deque.txt");

    //выделяем память под дек
    Deque<int> d;
     
    //добавляем значения в конец
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    //добавляем значения в начало
    d.push_front(6);
    d.push_front(7);
    d.push_front(8);
    d.push_front(9);
    d.push_front(10);


    f << "\n\nВывод дека возможен только или в файл, или на экран, я выбрала файл\n\n";

    
    f << "\n\nСначала выводим числа с 10 до 6, а потом с 1 до 5\n\n";


    //Пройдемся по всему деку и выведем значения
    while (!d.empty())
    {
        f << d.pop_front() << "\t";
    }
    

    f << "\n\n";

    cout << "\n\nчекните файл, результат там\n\n";
}