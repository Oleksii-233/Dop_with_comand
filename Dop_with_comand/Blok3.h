#pragma once

#ifndef BLOK3_H
#define BLOK3_H

#include "File_blok.h"
#include "Blok1.h"
#include "Blok2.h"

void Sort(fstream& file);

void ShowForGrades(fstream& file);

void Shap();

void Shap(student s);

void ShowPeopleForSubAndGrades(student* s, int k, int* subj, int* grades);

#endif 