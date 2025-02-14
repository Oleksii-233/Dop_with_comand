#pragma once

#ifndef FILE_BLOK_H
#define FILE_BLOK_H

#include <iostream>
#include <iomanip>
#include <fstream>

struct student {
	char name[20], surname[20], group[10];
	int math[3], phisic[3], english[3], ukrainian[3];
	double averM = 0, averP = 0, averE = 0, averU = 0;
};

using namespace std;

void IsOpen(fstream& file);

bool IsEmpty(fstream& file);

#endif
