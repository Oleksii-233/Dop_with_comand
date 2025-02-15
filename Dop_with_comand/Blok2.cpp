#include "Blok2.h"

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