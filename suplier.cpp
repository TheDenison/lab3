#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <iomanip> 
#include <cstring>
#include <string.h>
#include <windows.h>
#include "date.h"
#include "suplier.h"
using namespace std;

suplier::suplier() {         //�����������
	firma = new char[60];
	strcpy(firma, " ");
	adres = new char[60];
	strcpy(adres, " ");
	type = 0;
	balance = 0;
}

suplier:: ~suplier() {        //����������
	delete[] firma;
	delete[] adres;
}

void suplier::print_menu() {
	cout << "\t���� ������: ������������ (����������)\n";
	cout << "\t\t����\n";
	cout << "__________________________________________________________________\n";
	cout << "\t1 -->> �������� ����� �������\n";
	cout << "__________________________________________________________________\n";
	cout << "\t2 -->> ����������� ���� �����������\n";
	cout << "__________________________________________________________________\n";
	cout << "\t3 -->> ����� ���������� �� �������� �����\n";
	cout << "__________________________________________________________________\n";
	cout << "\t4 -->> ������ �� ����(����� ����������� ��������� ����)\n";
	cout << "__________________________________________________________________\n";
	cout << "\t5 -->> ����������� �� ���������� ������\n";
	cout << "__________________________________________________________________\n";
	cout << "\t6 -->> ����� ��� �������� � �������� ����� \n";
	cout << "__________________________________________________________________\n";
	cout << "\t7 -->> ����� ��� �������� � ����� ������, ��� ��������\n";
	cout << "__________________________________________________________________\n";
	cout << "\t8 -->> ����� �� ���������\n";
	cout << "__________________________________________________________________\n";
};

int suplier::scan_flag() {
	int a;
	while ((scanf("%d", &a)) != 1) {
		cout << "������� ������������ �������, ���������� ��� ���: ";
		scanf("%*[^\n]");
	}
	return(a);
};

int suplier::scan_int() {
	int a;
	while ((scanf("%d", &a)) != 1) {
		cout << "������� ������������ �������, ���������� ��� ���: ";
		scanf("%*[^\n]");
	}
	return(a);
};

int suplier::scan_double() {
	double a;
	while ((scanf("%lf", &a)) != 1) {
		cout << "������� ������������ �������, ���������� ��� ���: ";
		scanf("%*[^\n]");
	}
	return(a);
};

int suplier::scan_type() {
	int type = 0;
	while (type != 1 && type != 2) {
		type = scan_int();
		if (type == 1 || type == 2) {
			break;
		}
		cout << "������� ������������ �������, ���������� ��� ���: ";
	}
	return type;
}

void suplier::scan_month(char* buf) {
	int i = 0;
	int k = 1;
	while (k != 0) {
		if (i > 0) printf("������� ����� �����(���������� � ��������� �����): ");
		scanf("%s", buf);
		if (strcmp(buf, "������") == 0) k = 0;
		if (strcmp(buf, "�������") == 0) k = 0;
		if (strcmp(buf, "����") == 0) k = 0;
		if (strcmp(buf, "������") == 0) k = 0;
		if (strcmp(buf, "���") == 0) k = 0;
		if (strcmp(buf, "����") == 0) k = 0;
		if (strcmp(buf, "����") == 0) k = 0;
		if (strcmp(buf, "������") == 0) k = 0;
		if (strcmp(buf, "��������") == 0) k = 0;
		if (strcmp(buf, "�������") == 0) k = 0;
		if (strcmp(buf, "������") == 0) k = 0;
		if (strcmp(buf, "�������") == 0) k = 0;
		i++;
	}
}

int suplier::month_in_digit(suplier* m) {
	if (strcmp(m->date.month, "������") == 0)   return 1;
	if (strcmp(m->date.month, "�������") == 0)  return 2;
	if (strcmp(m->date.month, "����") == 0)     return 3;
	if (strcmp(m->date.month, "������") == 0)   return 4;
	if (strcmp(m->date.month, "���") == 0)      return 5;
	if (strcmp(m->date.month, "����") == 0)     return 6;
	if (strcmp(m->date.month, "����") == 0)     return 7;
	if (strcmp(m->date.month, "������") == 0)   return 8;
	if (strcmp(m->date.month, "��������") == 0) return 9;
	if (strcmp(m->date.month, "�������") == 0)  return 10;
	if (strcmp(m->date.month, "������") == 0)   return 11;
	if (strcmp(m->date.month, "�������") == 0)  return 12;
}

void suplier::print_tabl() {
	printf("\n___________________________________________________________________________________________________________");
	printf("\n�����\t\t����������� �����\t\t��� ����������\t\t������\t\t����");
	printf("\n___________________________________________________________________________________________________________");
}

void suplier::print_info(int i, suplier* m) {
	printf("\n%s\t\t", m[i].get_firma());
	printf("%15s\t\t", m[i].get_adres());
	printf("%15d\t\t", m[i].type);
	printf("%15lf\t\t", m[i].balance);
	printf("%2d", m[i].date.get_day());
	printf(" %10s", m[i].date.get_month());
	printf(" %4d", m[i].date.get_year());
	printf("\n___________________________________________________________________________________________________________");
};

istream& operator>>(istream& is, suplier& t) {
	char buf[60];
	//���� �������� �����
	cout << "\t���������� ������ ��������!\n";
	cout << "�������� ����� ����������: ";
	is >> buf;
	//delete[] t.firma;
	t.firma = new char[strlen(buf) + 1];
	t.set_firma(buf);

	//���� ������������ ������
	cout << "����������� �����: ";
	is >> buf;
	//delete[] t.adres;
	t.adres = new char[strlen(buf) + 1];
	t.set_adres(buf);

	//���� ���� ����������
	cout << "��� ����������( 1 - �����, 2 - ������������): ";
	while (true) {
		is >> t.type;
		if (is.fail() || t.type > 2 || t.type < 1)
		{
			is.clear();
			is.ignore(32767, '\n');
			cout << "������� ������������ �������, ���������� ��� ���: ";
		}
		else break;
	}

	//���� ������
	cout << "������: ";
	while (true) {
		is >> t.balance;
		if (is.fail()) {
			is.clear();
			is.ignore(32767, '\n');
			cout << "������� ������������ �������, ���������� ��� ���: ";
		}
		else break;
	}
	//���� ����
	cout << "������� ���� ��������\n";
	//����
	cout << "����: ";
	while (true) {
		is >> t.date.day;
		if (is.fail() || t.date.day > 31 || t.date.day < 1) {
			is.clear();
			is.ignore(32767, '\n');
			cout << "������� ������������ �������, ���������� ��� ���: ";
		}
		else break;
	}
	//�����
	cout << "�����(�����): ";
	is >> buf;
	while ((strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0) && strcmp(buf, "����") != 0 && strcmp(buf, "������") != 0 && (strcmp(buf, "���") != 0 && strcmp(buf, "����") != 0 && (strcmp(buf, "����") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "��������") != 0) && (strcmp(buf, "�������") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0))) {
		cout << "������� ������������ �������, ���������� ��� ���: ";
		is >> buf;
	}
	t.date.month = new char[strlen(buf) + 1];
	t.date.set_month(buf);
	//���
	cout << "���: ";
	while (true) {
		is >> t.date.year;
		if (is.fail() || t.date.year < 1) {
			is.clear();
			is.ignore(32767, '\n');
			cout << "������� ������������ �������, ���������� ��� ���: ";
		}
		else break;
	}
	return is;
}

void suplier::function_1(suplier*& m) {       //�������� ����� �������
	char buf[60];
	gets_s(buf);
	suplier* t = new suplier[n + 1];
	for (int i = 0; i < n; i++) {
		t[i] = m[i];
	}
	cin >> t[n];
	cout << "\n\t��������� ������� �������!\n";
	printf("___________________________________________________________________________________________________________\n");
	suplier::n++;
	delete[] m;
	m = t;
};

void suplier::function_2(suplier* m) {      //����������� ���� �����������
	printf("\t\t\t���� �����������");
	print_tabl();
	for (int i = 0; i < n; i++) {
		print_info(i, m);
	}
}

void function_3(suplier* m) {     //����� ���������� �� �������� �����
	char buf[100];
	printf("������� �������� ����� ����������: ");
	gets_s(buf);
	gets_s(buf);
	char* name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	m->print_tabl();
	for (int i = 0; i < suplier::n; i++) {
		if (strcmp(m[i].get_firma(), name) == 0) {
			m->print_info(i, m);
		}
	}
	printf("\n���� ���������� �� ��������, ��������� �������� ������!");
	delete[] name;
	printf("\n___________________________________________________________________________________________________________");
};

void suplier::function_4(suplier* m) {        //������ �� ����(����� ����������� ��������� ����)
	printf("������� ��� ����������(1- ��������� �����, 2- ��������� ������������): ");
	int typ = 0;
	while (true) {
		typ = scan_int();
		if (typ == 1 || typ == 2) {
			break;
		}
		else printf("������� ������������ �������, ���������� ��� ���: ");
		typ = scan_int();
	}
	print_tabl();
	for (int i = 0; i < n; i++) {
		if (m[i].type == typ) {
			print_info(i, m);
		}
	}
	printf("\n���� ���������� �� ��������, ��������� �������� ������!");
	printf("\n___________________________________________________________________________________________________________");
};

void suplier::function_5(suplier* m) {         //����������� �� ���������� ������
	print_tabl();
	suplier t;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (m[j].balance < m[j + 1].balance) {
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		print_info(i, m);
	}
};

void suplier::function_6(suplier* m) {              //����� ��� �������� � �������� �����
	char buf[100];
	suplier* date_now = new suplier[1];
	//��������� ����
	cout << "������� ������� ����\n";

	//����
	cout << "����: ";
	date_now->date.day = scan_int();

	//�����
	cout << "�����(�����): ";
	scan_month(buf);
	delete[] date_now->date.month;
	date_now->date.month = new char[strlen(buf) + 1];
	date_now->date.set_month(buf);

	//���
	cout << "���: ";
	date_now->date.year = scan_int();

	print_tabl();
	for (int i = 0; i < n; i++) {
		int month = month_in_digit(&m[i]);
		int month_now = month_in_digit(date_now);
		if ((date_now->date.year == m[i].date.year) && (month_now == month) && (date_now->date.day == m[i].date.day)) {
			print_info(i, m);
		}
	}
	delete[] date_now;
}

void suplier::function_7(suplier* m) {              //����� ��� �������� � ����� ������, ��� ��������
	char buf[100];
	suplier* date_now = new suplier[1];

	//��������� ����
	cout << "������� ������� ����\n";

	//����
	cout << "����: ";
	date_now->date.day = scan_int();

	//�����
	cout << "�����(�����): ";
	scan_month(buf);
	delete[] date_now->date.month;
	date_now->date.month = new char[strlen(buf) + 1];
	date_now->date.set_month(buf);

	//���
	cout << "���: ";
	date_now->date.year = scan_int();

	print_tabl();
	for (int i = 0; i < n; i++) {
		int month = month_in_digit(&m[i]);
		int month_now = month_in_digit(date_now);

		if (date_now->date.year < m[i].date.year) {
			print_info(i, m);
		}
		else if ((date_now->date.year == m[i].date.year) && (month_now < month)) {
			print_info(i, m);
		}
		else if ((date_now->date.year == m[i].date.year) && (month_now == month) && (date_now->date.day < m[i].date.day)) {
			print_info(i, m);
		}
	}
	delete[] date_now;
}

void suplier::save_work(suplier* m) {
	FILE* pf;
	pf = fopen("companies.txt", "w+");
	fprintf(pf, "%i\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(pf, "%s ", m[i].get_firma());
		fprintf(pf, "%s ", m[i].get_adres());
		fprintf(pf, "%i ", m[i].type);
		fprintf(pf, "%lf ", m[i].balance);
		fprintf(pf, "%i ", m[i].date.get_day());
		fprintf(pf, "%s ", m[i].date.get_month());
		fprintf(pf, "%i\n", m[i].date.get_year());
	}
	fclose(pf);
};

suplier* suplier::load_work(suplier* m) {
	FILE* pf;
	char buf[100];
	suplier* t = new suplier[1];
	pf = fopen("companies.txt", "r");
	delete[] m;

	//��������� ����������
	fscanf(pf, "%s", buf);
	n = atoi(buf);

	m = new suplier[n + 1];
	suplier::n = 0;
	for (int i = 0; !feof(pf); i++) {
		//��������� ��������
		fscanf(pf, "%s", buf);
		delete[] t->firma;
		t->firma = new char[strlen(buf) + 1];
		t->set_firma(buf);

		//��������� �����
		fscanf(pf, "%s", buf);
		delete[] t->adres;
		t->adres = new char[strlen(buf) + 1];
		t->set_adres(buf);

		//��������� ���
		fscanf(pf, "%s", buf);
		t->type = atoi(buf);

		//��������� ������
		fscanf(pf, "%s", buf);
		t->balance = atof(buf);

		//���������� ����
		fscanf(pf, "%s", buf);
		t->date.set_day(atoi(buf));

		//��������� �����
		fscanf(pf, "%s", buf);
		delete[] t->date.month;
		t->date.month = new char[strlen(buf) + 1];
		t->date.set_month(buf);

		//��������� ���
		fscanf(pf, "%s", buf);
		t->date.set_year(atoi(buf));
		suplier::n++;

		m[i] = *t;
	}
	fclose(pf);
	delete[] t;
	return m;
};