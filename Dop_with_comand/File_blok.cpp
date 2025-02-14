#include "File_blok.h"

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

	return k;

}