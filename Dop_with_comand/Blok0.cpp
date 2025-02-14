#include "Blok0.h"

void ShowOne() {
	cout << setw(20) << "Surname" << setw(20) << "Name" << setw(9) << "Math_grades" << setw(9) << "Phisics_grades" << setw(9) << "English_grades" << setw(9) << "Ukrainian_grades" << setw(10) << "Group" << endl;
}

void Show_Grades(int* arr) {
	for (int i = 0; i < 3; i++) {
		cout << setw(3) << *(arr + i);
	}

}

void ShowOne(student s) {
	cout << setw(20) << s.surname << setw(20) << s.name;
	Show_Grades(s.math); Show_Grades(s.phisic); Show_Grades(s.english); Show_Grades(s.ukrainian);
	cout << setw(10) << s.group << endl;
}

int NormalNumber() {
	int num;
	do{
		cin >> num;
	} while (num <= 0);

	return num;
}

void Enter_grades(int* arr) {

	for (int i = 0; i < 3; i++) {
		cout << "Enter " << i + 1 << " from this subject: ";
		*(arr + i) = NormalNumber();
	}

}

void EnterPeople(student& s) {
	cout << "Enter people surname: "; cin.ignore();  cin.getline(s.surname, 20);
	cout << "Enter people name: "; cin.getline(s.name, 20);
	cout << "Enter people grades from math:\n"; Enter_grades(s.math);
	cout << "Enter people grades from phisics:\n"; Enter_grades(s.phisic);
	cout << "Enter people grades from english:\n"; Enter_grades(s.english);
	cout << "Enter people grades from ukrainian:\n"; Enter_grades(s.ukrainian);
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

	if (IsEmpty(file))
		cout << "File is empty." << endl;
	else
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