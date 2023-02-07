#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class date
{
private:
	int day, month, year;
public:
	/**********������������**********/

	date();						//����������� �� ���������
	date(int d, int m, int y);	//����������� � �����������

	
	/**********������**********/
	
	void SetDay(int d);		//������ ����
	void SetMonth(int m);	//������ �����
	void SetYear(int y);	//������ ���


	/**********������**********/

	int GetDay() const;		//��������� ����
	int GetMonth() const;	//���������� �����
	int GetYear() const;	//���������� ���


	/**********������**********/
	
	string AllDate() const;				//��������� ���� � ������
	//void SetAll(int d, int m, int y);	//������ ���� ���������
	void Addition();	//��������� ���� ����
	void DayOutScreen();				//����� �� �����
	void DayOutFile();					//����� � ����
};