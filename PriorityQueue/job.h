#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//приоритет работников
enum Staff {Manager, Supervisor, Worker};


//врем€, потраченное на работу дл€ каждой категории сотрудников
int JobServisUse[3] = { 0, 0, 0 };


//структура определ€ющий запрос
struct JobRequest
{
	Staff staffPerson;
	int JobId;
	int JobTime;
};


/// <summary>
/// ѕерегрузка оператора меньше дл€ 
/// двух объектов JobRequest
/// </summary>
/// <param name="job1"></param>
/// <param name="job2"></param>
/// <returns></returns>
bool operator < (const JobRequest& job1, const JobRequest& job2)
{
	return job1.staffPerson < job2.staffPerson;
}


/// <summary>
/// ѕечать одной записи JobRequest
/// </summary>
/// <param name="PR">print</param>
void PrintJobInfo(JobRequest PR)
{
	switch (PR.staffPerson)
	{
	case Manager:
		cout << "Manager\t" << PR.JobId << "\t" << PR.JobTime << "\n";
		break;
	case Supervisor:
		cout << "Supervisor\t" << PR.JobId << "\t" << PR.JobTime << "\n";
		break;
	case Worker:
		cout << "Worker\t" << PR.JobId << "\t" << PR.JobTime << "\n";
		break;

	default:
		break;
	}
}


//ѕечать общего времени работы сотрудников
void PrintJobSummery(int JobServiceUse[])
{
	cout << "\n¬рем€ обслуживани€ по категори€м: \n";

	cout << "Manager\t" << setw(3) << JobServiceUse[0] << "\n";

	cout << "Supervisor\t" << setw(3) << JobServiceUse[1] << "\n";

	cout << "Worker\t" << setw(3) << JobServiceUse[2] << "\n";
}