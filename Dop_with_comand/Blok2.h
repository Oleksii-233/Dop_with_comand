#pragma once

#ifndef BLOK2_H
#define BLOK2_H

#include "File_blok.h"
#include "Blok1.h"

void EnterNumSub(int& num);

void Surnames(fstream& file);

void Grades(fstream& file);

void Sorting(student* s, int size);

void ShowArr(student* s, int k);

void ShowPeopleGradesFromSubject(fstream& file);

#endif