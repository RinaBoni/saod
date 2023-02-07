#include "date.h"

/**********конструкторы**********/

//значения по умолчанию
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

/**********сетеры**********/

//задаем день
void date::SetDay(int d)
{
	if ((1 <= d) && (d <= 31))
		this->day = d;
	else throw invalid_argument("invalid_argument");
}

//задаем месяц
void date::SetMonth(int m)
{
	if ((1 <= m) && (m <= 12))
		this->month = m;
	else throw invalid_argument("invalid_argument");
}

//задаем год
void date::SetYear(int y)
{
	if (1 <= y)
		this->year = y;
	else throw invalid_argument("invalid_argument");
}


/**********гетеры**********/

//возращаем день
int date::GetDay() const
{
	return this->day;
}

//возвращаем месяц
int date::GetMonth() const
{
	return this->month;
}

//возвращаем год
int date::GetYear() const
{
	return this->year;
}


/**********методы**********/

//соединяет дату в строке
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

/*//задает дату полностью
void date::SetAll(int d, int m, int y)
{
	SetDay(d);
	SetMonth(m);
	SetYear(y);
}*/

//добавляет один день
void date::Addition()
{
	day += 1;				//увеличиваем дни
	if (day > 31)			//если месяц закончился, начинается новый
	{
		day = 1;
		month += 1;
		if (month > 12)		//если год закончился, начинается новый
		{
			month = 1;
			year += 1;
		}
	}
}

//вывод на экран
void date::DayOutScreen()
{
	cout << AllDate() << "\n";
}

//вывод в файл
void date::DayOutFile()
{
	string path = "date.txt";	//название файла f
	ofstream file_date;			//создаем фаил для записи
	file_date.open(path);		//открываем файл для записи, связываем с именем
	if (!file_date.is_open())	//если не удалось открыть
	{
		cout << "file open error1" << endl;//сообщаем об этом
	}
	else//если открылся
	{
		cout << "file opened successfully" << endl;
		file_date << AllDate();	//записываем строку в файл
	}
	cout  << "\n";
	file_date.close();			//закрываем файл
}
