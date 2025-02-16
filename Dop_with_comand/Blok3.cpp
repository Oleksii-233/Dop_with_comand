#include "Blok3.h"

#include <iostream>

void Sort(fstream& file) {
	student s[15];

	IsOpen(file);

	if (IsEmpty(file)) {
		string text = "File is empty.";
		cout << text << endl;
		App(text);
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

// Приймає масив з номерів предметів та масив із відповідних оцінок для цих предметів, номера предметів і оцінок відповідні
void ShowPeopleForSubAndGrades(student* s, int k, int* subj, int* grades) {
	bool find = false;

	for (int i = 0; i < k; i++) 
		if (s[i].sub[subj[0]].grade == grades[0] && s[i].sub[subj[1]].grade == grades[1] && s[i].sub[subj[2]].grade == grades[2])
			find = true;

	if (find) {
		Shap();
		App();

		for (int i = 0; i < k; i++)
			if (s[i].sub[subj[0]].grade == grades[0] && s[i].sub[subj[1]].grade == grades[1] && s[i].sub[subj[2]].grade == grades[2]) {
				Shap(s[i]);
				App(s[i]);
			}

	}
	else {
		string text = "Not find";
		cout << text << endl;
		App(text);
	}
}

void ShowForGrades(fstream& file) {

	IsOpen(file);

	if (IsEmpty(file)) {
		string text = "File is empty.";
		cout << text << endl;
		App(text);
		return;
	}

	student s[15];
	int k = GetCountFromFile(file, s);

	string t = "Have 5 from english, phisics ans 3 from math: ";
	cout << t << endl;
	App(t);
	int subjects[] = { 2,1,0 }; int grades[] = { 5,5,3 };
	ShowPeopleForSubAndGrades(s, k, subjects, grades);

	t = "Have 3 from ukrainian, english and 4 from phisics ";
	cout << t << endl;
	App(t);
	int subjects0[] = { 3,2,1 }; int grades0[] = { 3,3,4 };
	ShowPeopleForSubAndGrades(s, k, subjects0, grades0);

	t = "Have 5 from math, 3 from phisic, 4 fron english";
	cout << t << endl;
	App(t);

	int subjects1[] = { 0,1,2 }; int grades1[] = { 5,3,4 };
	ShowPeopleForSubAndGrades(s, k, subjects1, grades1);
	
}