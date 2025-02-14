#include "Blok0.h"

void ShowOne() {
	cout << setw(20) << "Surname" << setw(20) << "Name" << setw(9) << "Math_grades" << setw(9) << "Phisics_grades" << setw(9) << "English_grades" << setw(9) << "Ukrainian_grades" << setw(10) << "Group" << endl;
}

void ShowOne(student s) {
	cout << setw(20) << s.surname << setw(20) << s.name << setw(10) << s.group << setw(10) << s.math << setw(10) << s.phisic << setw(10) << s.english << setw(10) << s.ukrainian << endl;
}

int NormalNumber() {
	int num;

	do{
		cin >> num;
	} while (num <= 0);

	return num;
}

void EnterPeople(student& s) {
	cout << "Enter people surname: "; cin.ignore();  cin.getline(s.surname, 20);
	cout << "Enter people name: "; cin.getline(s.name, 20);
	cout << "Enter people grades from math: "; cin >> s.math;
	cout << "Enter people grades from phisics: "; cin >> s.phisic;
	cout << "Enter people grades from english: ";cin >> s.english;
	cout << "Enter people grades from ukrainian: "; cin >> s.ukrainian;
}

void WriteInFile(fstream& file) {
	student s;
	int n;

	IsOpen(file);

	cout << "Enter count of people: "; n = NormalNumber();

	for (int i = 0; i < n; i++) {
		EnterPeople(s);
		file.write((char*)&s, sizeof(s));
	}
	
}

void ShowAllFile(fstream& file) {
	student s;

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

		ShowOne();

	while (file.read((char*)&s, sizeof(s)))
		ShowOne(s);
	
}

void AppendInFile(fstream& file) {
	student s;
	int n;

	IsOpen(file);

	cout << "Enter count of people: "; n = NormalNumber();

	for (int i = 0; i < 1; i++) {
		EnterPeople(s);
		file.write((char*)&s, sizeof(s));
	}

}