#pragma once

#ifndef FILE_BLOK_H
#define FILE_BLOK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct student {
	char name[20], surname[20], group[10];

	int math, phisic, english, ukrainian;
	double aver = 0;
};

using namespace std;

void IsOpen(fstream& file);

bool IsEmpty(fstream& file);

#endif
