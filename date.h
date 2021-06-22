#pragma once
#pragma warning(suppress : 4996)
#include <string.h>
#include <iostream>

using namespace std;

class suplier;

class date
{
private:
	int day;            //день
	char* month;        //месяц
	int year;           //год
public:
	int get_day() { return day; };
	char* get_month() { return month; };
	int get_year() { return year; };
	void set_day(int a) { day = a; };
	void set_month(char* a) { strcpy(month, a); };
	void set_year(int a) { year = a; };
	friend class suplier;
	friend istream& operator>>(istream& is, suplier& t);
	date();             //конструктор по-умолчанию
	~date();            //деструктор
};
