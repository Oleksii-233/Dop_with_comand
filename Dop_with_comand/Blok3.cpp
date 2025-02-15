#include "Blok3.h"

#include <iostream>

void Sort(fstream& file) {
	student s[15];

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}


	int k = GetCountFromFile(file, s);

	Sorting(s, k);
	ShowArr(s, k);

}

void Shap() {
	cout << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Group" << endl;
}

void Shap(student s) {
	cout << setw(20) << s.surname << setw(20) << s.name << setw(10) << s.group << endl;
}

// ������ ����� � ������ �������� �� ����� �� ��������� ������ ��� ��� ��������, ������ �������� � ������ �������
void ShowPeopleForSubAndGrades(student* s, int k, int* subj, int* grades) {
	bool find = false;

	for (int i = 0; i < k; i++) 
		if (s[i].sub[subj[0]].grade == grades[0] && s[i].sub[subj[1]].grade == grades[1] && s[i].sub[subj[2]].grade == grades[2])
			find = true;

	if (find) {
		Shap();

		for (int i = 0; i < k; i++)
			if (s[i].sub[subj[0]].grade == grades[0] && s[i].sub[subj[1]].grade == grades[1] && s[i].sub[subj[2]].grade == grades[2])
				Shap(s[i]);

	}
	else
		cout << "Not find" << endl;
	
}

void ShowForGrades(fstream& file) {

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	student s[15];
	int k = GetCountFromFile(file, s);

	cout << "Have 5 from english, phisics ans 3 from math: " << endl;
	int subjects[] = { 2,1,0 }; int grades[] = { 5,5,3 };
	ShowPeopleForSubAndGrades(s, k, subjects, grades);

	cout << "Have 3 from ukrainian, english and 4 from phisics " << endl;
	int subjects0[] = { 3,2,1 }; int grades0[] = { 3,3,4 };
	ShowPeopleForSubAndGrades(s, k, subjects0, grades0);

	cout << "Have 5 from math, 3 from phisic, 4 fron english" << endl;
	int subjects1[] = { 0,1,2 }; int grades1[] = { 5,3,4 };
	ShowPeopleForSubAndGrades(s, k, subjects1, grades1);
	
}