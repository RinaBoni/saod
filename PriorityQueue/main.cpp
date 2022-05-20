/*
* Лаб.работа № 10. Очереди приоритетов.
* 1. Создать класс PQueue.
* 2. Реализовать программу №5.6, Выполнение заданий.
*/


#include <iostream>
#include <fstream>
#include "PQueue.h"
#include "job.h"

using namespace std;

int main()
{
    system("chcp1251");

    PQueue<JobRequest> jobpool;

    int JobServisUse[3] = { 0, 0, 0 };

    JobRequest PR;

    char ch;

    ifstream f;

    f.open("job.txt", ios::in | ios::_Nocreate);

    if (f.is_open())
    {
        //Читаем файл
        while (f >> ch)
        {
            //Смотрим что за работник
            switch (ch)
            {
            case 'M':
                PR.staffPerson = Manager;
            
            case 'S':
                PR.staffPerson = Supervisor;
            
            case 'W':
                PR.staffPerson = Worker;
            
            default:
                cout << "Вы написали что-то не то\n";
                break;
            }

            //Читаем остальные данные по работнику
            f >> PR.JobId;
            f >> PR.JobTime;

            //вставляем в очередь
            jobpool.push(PR);
        }
        cout << "Категория\tНомер\tВремя\n\n";

        while (!jobpool.empty())
        {
            PR = jobpool.pop();
            PrintJobInfo(PR);

            //Добавляем время
            JobServisUse[(int)PR.staffPerson] += PR.JobTime;
        }
        PrintJobSummery(JobServisUse);
    }
    else
    {
        cout << "Не получается открыть файл";
    }
}