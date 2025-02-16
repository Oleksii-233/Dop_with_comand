#include "Blok0.h"

void ShowOne() {
	cout << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Math" << setw(10) << "Phisics" << setw(10) << "English" << setw(10) << "Ukrainian" << setw(10) << "Group" << endl;
}

void ShowOne(student s) {
	cout << setw(20) << s.surname << setw(20) << s.name;

	for (int i = 0; i < 4; i++) 
		cout << setw(10) << s.sub[i].grade;
	

	cout << setw(10) << s.group << endl;

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
	cout << "Enter people group: "; cin.getline(s.group, 10);

	for (int i = 0; i < 4; i++) {
		cout << "Grade from " << s.sub[i].name << " is: "; s.sub[i].grade = NormalNumber();
	}

	

}

void WriteInFile(fstream& file) {
	student s;
	int n;

	IsOpen(file);

	string text = "Enter count of people: ";
	cout << text; n = NormalNumber();
	App(text); App(to_string(n));

	App();
	for (int i = 0; i < n; i++) {
		EnterPeople(s);
		App(s);
		file.write((char*)&s, sizeof(s));
	}
	
}

void ShowAllFile(fstream& file) {
	student s;

	IsOpen(file);

	if (IsEmpty(file)) {
		string text = "File is empty.";
		App(text);
		cout << text << endl;
		return;
	}

		ShowOne();
		App();

		while (file.read((char*)&s, sizeof(s))) {
			ShowOne(s);
			App(s);
		}
}

void AppendInFile(fstream& file) {
	student s;
	int n;

	IsOpen(file);

	string text = "Enter count of people: ";
	cout << text; n = NormalNumber();
	App(text), App(to_string(n)); App();

	for (int i = 0; i < n; i++) {
		EnterPeople(s);
		App(s);
		file.write((char*)&s, sizeof(s));
	}

}