#include "Blok2.h"

void EnterNumSub(int& num) {
	do {
		cin >> num;
		App(to_string(num));
	} while (num < 0 || num > 4);
}

void Sorting(student* s, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(s[i].group, s[j].group) > 0)
				swap(s[i], s[j]);
}

void ShowArr(student* s, int k) {
	for (int i = 0; i < k; i++) {
		ShowOne(s[i]);
		App(s[i]);
	}

}

void Surnames(fstream& file) {
	student s[15], stud;
	int size = 0, k = 0;

	IsOpen(file);

	if (IsEmpty(file)) {
		string text = "File is empty.";
		cout <<  text << endl;
		App(text);
		return;
	}

	size = GetCountFromFile(file, s);

	char fname[20];

	string text0 = "Enter searching surname: ";
	cout << text0;
	
	cin.getline(fname, 20);
	
	App(text0); App(fname);

	student n[15];
	int nsize = 0;

	for (int i = 0; i < size; i++) 
		if (strcmp(s[i].surname, fname) == 0) 
			n[nsize++] = s[i];
		
	if (nsize < 2) {
		string text1 = "People not find.";
		cout << text1 << endl;
		App(text1);
		return;
	}

	App();
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
		string text = "File is empty.";
		cout <<  text << endl;
		App(text);
		return;
	}

	student s[15];
	int k = GetCountFromFile(file, s);

	int n_sub[4], a = 0;

	string text1 = "Enter two numbers of subjects (0 - math, 1 - phisic, 2 - english, 3 - ukrainian): ";
	cout << text1 << endl;
	App(text1);
	
	for (int i = 0; i < 2; i++)
		EnterNumSub(n_sub[i]);

	string text2 = "Students who have 4 or 5 from 2 subjects: ";
	cout << text2 << endl;
	App(text2);
	App();

	ShowOne();
	for (int i = 0; i < k; i++) 
		if (s[i].sub[n_sub[0]].grade == 4 || s[i].sub[n_sub[0]].grade == 5 && s[i].sub[n_sub[1]].grade == 4 || s[i].sub[n_sub[1]].grade == 5) {
			a++;
			ShowOne(s[i]);
			App(s[i]);
		}

	if (!a) {
		string msg = "Not Find.";
		cout << msg << endl;
		App(msg);
	}
	a = 0;

	string text3 = "Enyer three numbers of subjects (0 - math, 1 - phisic, 2 - english, 3 - ukrainian):";
	cout << text3;
	App(text3);
	for (int i = 0; i < 3; i++) 
		EnterNumSub(n_sub[i]);
	
	string text4 = "Students who have 3 or 4 from  3 subjects: ";
	cout << text4 << endl;
	App(text4);
	App();
	ShowOne();	
	for (int i = 0; i < k; i++) 
		if (s[i].sub[n_sub[0]].grade == 3 || s[i].sub[n_sub[0]].grade == 4 && s[i].sub[n_sub[1]].grade == 3 || s[i].sub[n_sub[1]].grade == 4 && s[i].sub[n_sub[2]].grade == 3 || s[i].sub[n_sub[2]].grade == 4) {
			a++;
			ShowOne(s[i]);
			App(s[i]);
		}

	if (!a) {
		string msg1 = "Not Find.";
		cout << msg1 << endl;
		App(msg1);
	}
		

	string text5 = "People, who have 5 or 3 from 4 subjects: ";
	cout << text5 << endl;
	App(text5);

	a = 0;
	bool have = true;
	
	ShowOne();
	App();
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) 
			if (s[i].sub[j].grade != 5 || s[i].sub[j].grade != 3) 
				have = false;
			
		if (have) {
			ShowOne(s[i]);
			App(s[i]);
			a++;
		}

	}

	if (!a) {
		string msg0 = "Not Find.";
		cout << msg0 << endl;
		App(msg0);
	}
		
}