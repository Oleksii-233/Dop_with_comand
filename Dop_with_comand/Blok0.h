#pragma once

#ifndef BLOK0_H
#define BLOK0_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "File_blok.h"

void ShowOne();

void ShowOne(student s);

void Show_Grades(int* arr);

int NormalNumber();

void Enter_grades(int* arr);

void EnterPeople(student& s);

void WriteInFile(fstream& file);

void ShowAllFile(fstream& file);

void AppendInFile(fstream& file);

#endif
