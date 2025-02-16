#include "Blok2.h"

void EnterNumSub(int& num) {
	do {
		cin >> num;
	} while (num < 0 || num > 4);
}

void Sorting(student* s, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(s[i].group, s[j].group) > 0)
				swap(s[i], s[j]);
}

void ShowArr(student* s, int k) {
	for (int i = 0; i < k; i++)
		ShowOne(s[i]);

}

void Surnames(fstream& file) {
	student s[15], stud;
	int size = 0, k = 0;

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	size = GetCountFromFile(file, s);

	char fname[20];

	cout << "Enter searching surname: ";
	cin.ignore(); cin.getline(fname, 20);

	bool add[15] = { false };
	student n[15];
	int nsize = 0;

	for (int i = 0; i < size - 1; i++) 
		for (int j = i + 1; j < size; j++) 
			if (strcmp(s[i].surname, fname) == 0 && strcmp(s[j].surname, fname) == 0) {
				if (!add[i]) {
					n[nsize++] = s[i];
					add[i] = true;
				}
				if (!add[j]) {
					n[nsize++] = s[j];
					add[j] = true;

				}
				k++;
			}
		
	if (!k) {
		cout << "People not find." << endl;
		return;
	}
		
	Sorting(n, nsize);
	ShowArr(n, nsize);

}

void Grades(fstream& file) {

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	student s[15];
	int k = 0;


}

void ShowPeopleGradesFromSubject(fstream& file) { 
	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	student s[15];
	int k = GetCountFromFile(file, s);

	int n_sub[4], a = 0;

	cout << "Enter two numbers of subjects (0 - math, 1 - phisic, 2 - english, 3 - ukrainian): " << endl;
	
	for (int i = 0; i < 2; i++)
		EnterNumSub(n_sub[i]);

	cout << "Students who have 4 or 5 from 2 subjects: " << endl;

	ShowOne();

	for (int i = 0; i < k; i++) 
		if (s[i].sub[n_sub[0]].grade >= 4 && s[i].sub[n_sub[1]].grade >= 4) {
			a++;
			ShowOne(s[i]);
		}

	if (!a)
		cout << "Not Find." << endl;

	a = 0;

	cout << "Enyer three numbers of subjects (0 - math, 1 - phisic, 2 - english, 3 - ukrainian):";

	for (int i = 0; i < 3; i++) 
		EnterNumSub(n_sub[i]);

	cout << "Students who have 3 or 4 from  3 subjects: " << endl;

	ShowOne();	
	for (int i = 0; i < k; i++) 
		if (s[i].sub[n_sub[0]].grade == 3 || s[i].sub[n_sub[0]].grade == 4 && s[i].sub[n_sub[1]].grade == 3 || s[i].sub[n_sub[1]].grade == 4 && s[i].sub[n_sub[2]].grade == 3 || s[i].sub[n_sub[2]].grade == 4) {
			a++;
			ShowOne(s[i]);
		}

	if (!a)
		cout << "Not find." << endl;

	cout << "People, who have 5 or 3 from 4 subjects: " << endl;
	
	a = 0;
	bool have = true;
	
	ShowOne();
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) 
			if (s[i].sub[j].grade != 5 || s[i].sub[j].grade != 3) 
				have = false;
			
		if (have) {
			ShowOne(s[i]);
			a++;
		}

	}

	if (!a)
		cout << "Not Find." << endl;

}