#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//��������� ����������
enum Staff {Manager, Supervisor, Worker};


//�����, ����������� �� ������ ��� ������ ��������� �����������
int JobServisUse[3] = { 0, 0, 0 };


//��������� ������������ ������
struct JobRequest
{
	Staff staffPerson;
	int JobId;
	int JobTime;
};


/// <summary>
/// ���������� ��������� ������ ��� 
/// ���� �������� JobRequest
/// </summary>
/// <param name="job1"></param>
/// <param name="job2"></param>
/// <returns></returns>
bool operator < (const JobRequest& job1, const JobRequest& job2)
{
	return job1.staffPerson < job2.staffPerson;
}


/// <summary>
/// ������ ����� ������ JobRequest
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


//������ ������ ������� ������ �����������
void PrintJobSummery(int JobServiceUse[])
{
	cout << "\n����� ������������ �� ����������: \n";

	cout << "Manager\t" << setw(3) << JobServiceUse[0] << "\n";

	cout << "Supervisor\t" << setw(3) << JobServiceUse[1] << "\n";

	cout << "Worker\t" << setw(3) << JobServiceUse[2] << "\n";
}