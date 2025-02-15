#include "Blok3.h"

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

void E_P_M(student* s, int k) {
	bool find = false;

	for (int i = 0; i < k; i++) 
		if (s[i].english == 5 && s[i].phisic == 5 && s[i].math == 3)
			find = true;

	if (find) {
		Shap();

		for (int i = 0; i < k; i++)
			if (s[i].english == 5 && s[i].phisic == 5&& s[i].math == 3)
				Shap(s[i]);

	}
	else
		cout << "Not find" << endl;
	
}

void U_P_E(student* s, int k) {
	bool find = false;

	for (int i = 0; i < k; i++)
		if (s[i].ukrainian == 3 && s[i].phisic == 4 && s[i].english == 3)
			find = true;

	if (find) {
		Shap();

		for (int i = 0; i < k; i++)
			if (s[i].ukrainian == 3 &&  s[i].phisic == 4 && s[i].english == 3)
				Shap(s[i]);

	}
	else
		cout << "Not find" << endl;

}

void M_P_E(student* s, int k) {
	bool find = false;

	for (int i = 0; i < k; i++)
		if (s[i].math == 5 && s[i].phisic == 3 && s[i].english == 4)
			find = true;

	if (find) {
		Shap();

		for (int i = 0; i < k; i++)
			if (s[i].math == 5 && s[i].phisic == 3 && s[i].english == 4)
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
	E_P_M(s, k);

	cout << "Have 3 from ukrainian, english and 4 from phisics " << endl;
	U_P_E(s, k);

	cout << "Have 5 from math, 3 from phisic, 4 fron english" << endl;
	M_P_E(s, k);
	

}