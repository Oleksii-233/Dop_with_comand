#include "File_blok.h"

fstream protocol;
char name[] = "fixator.txt";

void IsOpen(fstream& file) {
	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		return;
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

void App() {

	IsOpen(protocol);

	protocol << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Math" << setw(10) << "Phisics" << setw(10) << "English" << setw(10) << "Ukrainian" << setw(10) << "Group" << endl;

}

void App(string text) {

	IsOpen(protocol);

	protocol << text << endl;

}

void App(student s) {

	IsOpen(protocol);

	protocol << setw(20) << s.surname << setw(20) << s.name;

	for (int i = 0; i < 4; i++)
		protocol << setw(10) << s.sub[i].grade;


	protocol << setw(10) << s.group << endl;

}

void ReadFile() {

	protocol.open(name, ios::in);

	IsOpen(protocol);

	string Line;

	while (protocol >> Line)
		cout << Line << endl;

	protocol.close();

}