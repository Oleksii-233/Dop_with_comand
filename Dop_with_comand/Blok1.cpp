#define _CRT_SECURE_NO_WARNINGS

#include "Blok1.h"

#include "Blok2.h"


int GetCountFromFile(fstream& file, student* s) {
	student stud;
	int k = 0;

	while (file.read((char*)&s, sizeof(s)))
		s[k++] = stud;

	return k;

}

void Smallest(fstream& file) {
	student students[15], s;
	int k = 0;
	double min = INFINITY;

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	k = GetCountFromFile(file, students);

	for (int i = 0; i < k; k++) {
		
		for (int j = 0; j < 4; j++)
			students[i].aver += students[i].sub[j].grade;

		students[i].aver /= 4;

		if (min > students[i].aver)
			min = students[i].aver;
	}

	cout << "People with smallest average grade " << min << endl;

	ShowOne();

	for (int i = 0; i < k; i++) 
		if (students[i].aver == min)
			ShowOne(students[i]);
	
}

void CalcucaleAverInGroup(Group& g) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < g.k; j++) 
			g.sub[i].grade += g.s[j].sub[i].grade;
		
		g.sub[i].grade /= g.k;
	}

}

// 0 - Math, 1 - Phisic, 2 - English, 3 - Ukrainian

void GroupSort(Group* g, int size, int ind) { 

	for(int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++) 
			if (g[i].sub[ind].grade > g[j].sub[ind].grade)
				swap(g[i], g[j]);
		

}


void ShowArrGroup(Group* p, int s) {
	for (int i = 0; i < s; i++)
		cout << p[i].name;
}

void Reyt(fstream& file) {

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	student s[15]; 
	int k = 0;
	Group g[15];

	k = GetCountFromFile(file, s);

	strcpy(g[0].name, s[0].group);
	g[0].s[g[0].k++] = s[0];

	int size = 1;
	
	// Розподіл на групи
	for (int i = 1; i < k; i++) {
		bool find = false;

		for (int j = 0; j < size; j++) {

			if (strcmp(g[j].name, s[i].group) == 0) {
				find = true;
				g[j].s[g[j].k++] = s[i];
				break;
			}

		}

		if (!find) {
			g[size].s[g[size].k++] = s[i];
			strcpy(g[size++].name, s[i].group);
		}


	}

	for (int i = 0; i < size; i++)
		CalcucaleAverInGroup(g[i]);
	
	for (int i = 0; i < 4; i++) {
		cout << "Sorting group for this subject - " << g[0].s[0].sub[i].name << endl;
		GroupSort(g, size, i);
		ShowArrGroup(g, size);
	}

}