#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iomanip> 
#include <cstring>
#include <windows.h>
#include "date.h"
#include "suplier.h"
using namespace std;

date::date() {
	month = new char[60];
	strcpy(month, " ");
	day = 0;
	year = 0;
}
date:: ~date() {
	delete[] month;
}