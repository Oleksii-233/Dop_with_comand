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
		(students + i)->aver = (students[i].math + students[i].phisic + students[i].english + students[i].ukrainian) / 4.;
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

	for (int i = 0; i < g.k; i++) {
		g.aM += g.s[i].math;
		g.aP += g.s[i].phisic;
		g.aE += g.s[i].english;
		g.aU += g.s[i].ukrainian;
	}

	g.aM /= g.k;
	g.aP /= g.k;
	g.aE /= g.k;
	g.aU /= g.k;

}

void Math_s(Group* p, int s) {

	for (int i = 0; i < s - 1; i++)
		for (int j = i + 1; j < s; j++)
			if (p[i].aM > p[j].aM)
				swap(p[i], p[j]);

}

void Phicics_s(Group* p, int s) {

	for (int i = 0; i < s - 1; i++)
		for (int j = i + 1; j < s; j++)
			if (p[i].aP > p[j].aP)
				swap(p[i], p[j]);

}

void English_s(Group* p, int s) {

	for (int i = 0; i < s - 1; i++)
		for (int j = i + 1; j < s; j++)
			if (p[i].aE > p[j].aE)
				swap(p[i], p[j]);

}

void Ukrainian_s(Group* p, int s) {

	for (int i = 0; i < s - 1; i++)
		for (int j = i + 1; j < s; j++)
			if (p[i].aU > p[j].aU)
				swap(p[i], p[j]);

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
	
	cout << "Reyt for math: ";
	Math_s(g, size);
	ShowArrGroup(g, size);

	cout << "Reyt for phicics: ";
	Phicics_s(g, size);
	ShowArrGroup(g, size);

	cout << "Reyt for english: ";
	English_s(g, size);
	ShowArrGroup(g, size);

	cout << "Reyt for ukrainian: ";
	Ukrainian_s(g, size);
	ShowArrGroup(g, size);

}