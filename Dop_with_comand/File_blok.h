#pragma once

#ifndef FILE_BLOK_H
#define FILE_BLOK_H

#include <iostream>

#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

extern fstream protocol;

extern char name[];

struct subject {
	char name[10];

	int grade = 0;
};

struct student {
	char name[20], surname[20], group[10];

	subject sub[4] = { {"math",0}, {"phisiscs",0}, {"english",0}, {"ukrainian",0}};

	double aver = 0;
};


void IsOpen(fstream& file);

bool IsEmpty(fstream& file);

void App();

void App(string text);

void App(student s);

void ReadFile();

#endif
