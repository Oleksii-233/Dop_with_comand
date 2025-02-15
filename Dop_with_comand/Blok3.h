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

void E_P_M(student* s, int k);

void U_P_E(student* s, int k);

void M_P_E(student* s, int k);

#endif 