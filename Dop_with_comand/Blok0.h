#pragma once

#ifndef BLOK0_H
#define BLOK0_H

#include "File_blok.h"

void ShowOne();

void ShowOne(student s);

int NormalNumber();

void EnterPeople(student& s);

void WriteInFile(fstream& file);

void ShowAllFile(fstream& file);

void AppendInFile(fstream& file);

#endif
