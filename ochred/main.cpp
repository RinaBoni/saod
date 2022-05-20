// ochred.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <queue>
#include <random>
#include <math.h>
#include "Queue.h"

using namespace std;

struct Person
{
    string sex;         //пол
    string name;        //имя
};


int main()
{
    system("chcp1251");

    Queue<Person> female, male;

    Person person;

    ifstream f_persons;
    ofstream f("result.txt");

    f_persons.open("dance.txt");

    //если файл открылся
    if (f_persons.is_open())
    {
        //пока не дойдем до конца файла, считываем все данные
        while (!f_persons.eof())
        {
            //считываем в доп переменную, чтобы в конце файла создавалась еще одна запись
            string sex;
            f_persons >> sex;
            
            if (sex[0] == 'F' || sex[0] == 'f' || sex[0] == 'M' || sex[0] == 'm')
            {
                char name[20];
                f_persons.getline(name, 20);
                person.name = name;

                person.sex = sex;

                //смотрим на пол и заносим в соответствующую очередь
                if (person.sex[0] == 'M' || person.sex[0] == 'm')
                {
                    male.insert(person);
                }
                else if (person.sex[0] == 'F' || person.sex[0] == 'f')
                {
                    female.insert(person);
                }
            }
            else
            {
                cout << "Не получается считать пол\n";
            }
        }

        cout << "Партнеры по танцам:\n";
        f << "Партнеры по танцам:\n";

        //Пока одна из очередь не опустеет
        while (!male.empty() && !female.empty())
        {
            cout << male.front().name << " и " << female.front().name << "\n";
            f << male.delet().name << " и " << female.delet().name << "\n";
        }
        cout << "\n";

        if (!male.empty())
        {
            cout << "Танца ожидает еще " << male.size() << " кавалера";
            cout << " и первый на очереди " << male.front().name << "\n";
            f << "Танца ожидает еще " << male.size() << " кавалера";
            f << " и первый на очереди " << male.front().name << "\n";
        }

        if (!female.empty())
        {
            if (!male.empty())
            {
                cout << "А также ";
                f << "А также ";
            }
            cout << " Танца ожидает еще " << female.leght() << " дамы";
            cout << " и первая из них " << female.front().name;
            f << " Танца ожидает еще " << female.leght() << " дамы";
            f << " и первая из них " << female.front().name;
        }

    }
    else
    {
        cout << "Не получилось открыть файл";
        f << "Не получилось открыть файл";
    }

}