#include "date.h"

/**********������������**********/

//�������� �� ���������
date::date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

date::date(int d, int m, int y)
{
	SetDay(d);
	SetMonth(m);
	SetYear(y);
}

/**********������**********/

//������ ����
void date::SetDay(int d)
{
	if ((1 <= d) && (d <= 31))
		this->day = d;
	else throw invalid_argument("invalid_argument");
}

//������ �����
void date::SetMonth(int m)
{
	if ((1 <= m) && (m <= 12))
		this->month = m;
	else throw invalid_argument("invalid_argument");
}

//������ ���
void date::SetYear(int y)
{
	if (1 <= y)
		this->year = y;
	else throw invalid_argument("invalid_argument");
}


/**********������**********/

//��������� ����
int date::GetDay() const
{
	return this->day;
}

//���������� �����
int date::GetMonth() const
{
	return this->month;
}

//���������� ���
int date::GetYear() const
{
	return this->year;
}


/**********������**********/

//��������� ���� � ������
string date::AllDate() const
{
	string mnth;
	if (month == 1)
		mnth = "January";
	if (month == 2)
		mnth = "February";
	if (month == 3)
		mnth = "March";
	if (month == 4)
		mnth = "April";
	if (month == 5)
		mnth = "May";
	if (month == 6)
		mnth = "June";
	if (month == 7)
		mnth = "July";
	if (month == 8)
		mnth = "August";
	if (month == 9)
		mnth = "September";
	if (month == 10)
		mnth = "October";
	if (month == 11)
		mnth = "November";
	if (month == 12)
		mnth = "December";

	string date = to_string(day) + " " + mnth + " " + to_string(year);
	return date;
}

/*//������ ���� ���������
void date::SetAll(int d, int m, int y)
{
	SetDay(d);
	SetMonth(m);
	SetYear(y);
}*/

//��������� ���� ����
void date::Addition()
{
	day += 1;				//����������� ���
	if (day > 31)			//���� ����� ����������, ���������� �����
	{
		day = 1;
		month += 1;
		if (month > 12)		//���� ��� ����������, ���������� �����
		{
			month = 1;
			year += 1;
		}
	}
}

//����� �� �����
void date::DayOutScreen()
{
	cout << AllDate() << "\n";
}

//����� � ����
void date::DayOutFile()
{
	string path = "date.txt";	//�������� ����� f
	ofstream file_date;			//������� ���� ��� ������
	file_date.open(path);		//��������� ���� ��� ������, ��������� � ������
	if (!file_date.is_open())	//���� �� ������� �������
	{
		cout << "file open error1" << endl;//�������� �� ����
	}
	else//���� ��������
	{
		cout << "file opened successfully" << endl;
		file_date << AllDate();	//���������� ������ � ����
	}
	cout  << "\n";
	file_date.close();			//��������� ����
}
