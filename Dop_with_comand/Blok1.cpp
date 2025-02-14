#include "Blok1.h"

void Smallest(fstream& file) {
	student students[15], s;
	int k = 0;
	double min = INFINITY;

	IsOpen(file);

	if (IsEmpty(file)) {
		cout << "File is empty." << endl;
		return;
	}

	while (file.read((char*)&s, sizeof(s)))
		*(students + k++) = s;

	for (int i = 0; i < k; k++) {
		(students + i)->aver = (students[i].math + students[i].phisic + students[i].english + students[i].ukrainian) / 4.;
		if (min > students[i].aver)
			min = students[i].aver;
	}

	cout << "People with smallest average grade " << min << endl;

	ShowOne();

	for (int i = 0; i < k; i++) 
		if (students[i].aver == min)
			ShowOne(students[i]);
	
}