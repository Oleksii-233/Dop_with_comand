#pragma once

#ifndef BLOK1_H
#define BLOK1_H

#include "File_blok.h"
#include "Blok0.h"


struct Group {
	char name[10] = "";
	student s[15];
	int k = 0;

	subject sub[4] = { {"aM",0 } ,{"aP",0}, {"aE",0}, {"aU",0} };
};

void Smallest(fstream& file);

int GetCountFromFile(fstream& file, student* s);

void CalcucaleAverInGroup(Group& g);

void GroupSort(Group* g, int size, int ind);

void ShowArrGroup(Group* p, int s);

void Reyt(fstream& file);

#endif
