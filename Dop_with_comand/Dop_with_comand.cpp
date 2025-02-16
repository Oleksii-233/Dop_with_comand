#include "File_blok.h"

#include "Blok0.h"
#include "Blok1.h"
#include "Blok2.h"
#include "Blok3.h"

int main() {
	fstream file;
	char fileName[] = "People.dat";
	
	string text[] = { "0 - Create and write in file", "1 - Show all file on screen", "2 - Append in a file","3 - People with smallest average grade", "4 - Reyt for group", "5 - Data for peopel with identical surnames", "6 - Have 5, 4 from 2 subject, 4,3 from 3 subjects, 5,3 from 4 subjects", "7 - grades from subjects", "8 - sorting for group", "Another number to exit"};

	do {
		protocol.open(name, ios::out || ios::app || ios::binary);

		for (int i = 0; i < 10; i++) {
			cout << text[i] << endl;
			App(text[i]);
		}

		int a;
		cin >> a; cin.ignore();
		App(to_string(a));

		switch (a) {
		case 0: {
			file.open(fileName, ios::out | ios::binary);
			WriteInFile(file);
			file.close();
		}break;
		case 1: {
			file.open(fileName, ios::in | ios::binary);
			ShowAllFile(file);
			file.close();
		}break;
		case 2: {
			file.open(fileName, ios::app | ios::binary);
			AppendInFile(file);
			file.close();
		}break;
		case 3: {
			file.open(fileName, ios::in | ios::binary);
			Smallest(file);
			file.close();
		}break;
		case 4: {
			file.open(fileName, ios::in | ios::binary);
			Reyt(file);
			file.close();
		}break;
		case 5: {
			file.open(fileName, ios::in | ios::binary);
			Surnames(file);
			file.close();
		}break;
		case 6: {
			file.open(fileName, ios::in, ios::binary);
			ShowPeopleGradesFromSubject(file);
			file.close();
		}break;
		case 7: {
			file.open(fileName, ios::in | ios::binary);
			ShowForGrades(file);
			file.close();
		}break;
		case 8: {
			file.open(fileName, ios::in | ios::binary);
			Sort(file);
			file.close();
		}break;
		default: return 0;
		}

		protocol.close();

		if (a == 1111) 
			ReadFile();
		

	} while (true);
}