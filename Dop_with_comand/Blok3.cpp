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