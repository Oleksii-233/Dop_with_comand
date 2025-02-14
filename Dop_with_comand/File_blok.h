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

extern fstream protol;
extern char name[];

void IsOpen(fstream& file);

bool IsEmpty(fstream& file);

void Add();

void Add(string text);

void Add(student s);

void Read();

#endif
