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
	/**********конструкторы**********/

	date();						//Конструктор по умолчанию
	date(int d, int m, int y);	//Конструктор с параметрами

	
	/**********сетеры**********/
	
	void SetDay(int d);		//задаем день
	void SetMonth(int m);	//задаем месяц
	void SetYear(int y);	//задаем год


	/**********гетеры**********/

	int GetDay() const;		//возращаем день
	int GetMonth() const;	//возвращаем месяц
	int GetYear() const;	//возвращаем год


	/**********методы**********/
	
	string AllDate() const;				//соединяет дату в строке
	//void SetAll(int d, int m, int y);	//задает дату полностью
	void Addition();	//добавляет один день
	void DayOutScreen();				//вывод на экран
	void DayOutFile();					//вывод в файл
};