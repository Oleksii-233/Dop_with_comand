#include "File_blok.h"

extern fstream protocol;
extern char name[] = "protocol.txt";

void IsOpen(fstream& file) {

	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		exit(1);
	}

}

bool IsEmpty(fstream& file) {

	student s;
	int k = 0;

	IsOpen(file);

	while (file.read((char*)&s, sizeof(s)))
		k++;

	file.clear(); file.seekg(0);

	return !k;

}

void Add() {
	IsOpen(protocol);

	protocol << "Surname" << setw(20) << "Name" << setw(9) << "Math" << setw(9) << "Phisics" << setw(9) << "English" << setw(9) << "Ukrainian" << setw(10) << "Group" << endl;
}

void Add(string text) {

	IsOpen(protocol);

	protocol << text << endl;

}

void Add(student s) {

	IsOpen(protocol);

	protocol << setw(20) << s.surname << setw(20) << s.name << setw(10) << s.group << setw(10) << s.math << setw(10) << s.phisic << setw(10) << s.english << setw(10) << s.ukrainian << endl;

}

void Read() {
	protocol.open(name, ios::in);

	IsOpen(protocol);
	if (IsEmpty(protocol)) {
		cout << "Protocol is empty." << endl;
		return;
	}

	string line;

	while (getline(protocol, line))
		cout << line << endl;

	protocol.close();

}
