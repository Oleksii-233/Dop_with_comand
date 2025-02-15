#pragma once

#ifndef FILE_BLOK_H
#define FILE_BLOK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct subject {
	char name[10];

	int grade = 0;
};

struct student {
	char name[20], surname[20], group[10];

	subject sub[4] = { {"math",0}, {"phisiscs",0}, {"english",0}, {"ukrainian",0}};

	double aver = 0;
};

using namespace std;

void IsOpen(fstream& file);

bool IsEmpty(fstream& file);

#endif
