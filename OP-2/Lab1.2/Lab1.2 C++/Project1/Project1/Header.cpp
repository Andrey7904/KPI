#include "Header.h"


void create_note() {
	logs note;
	string timeg;
	ofstream outFile;
	outFile.open("text.txt", ios::binary);
	char c;
	do {
		cout << "Enter phone number: "; cin >> note.number;
		cout << "Enter start time (GG:XX): ";
		getline(cin, timeg, ':');
		cin >> note.startm;
		note.starth = stoi(timeg);

		cout << "Enter end time (GG:XX): ";
		getline(cin, timeg, ':');
		cin >> note.endm;
		note.endh = stoi(timeg);
		outFile.write((char*)&note, sizeof(logs));

		cout << "Continue? (Y/N)"; cin >> c;
	} while ((c != 'n') && (c != 'N'));
	outFile.close();
}

void printing() {
	ifstream inFile;
	inFile.open("text.txt", ios::binary);
	logs note;
	cout << endl << "Information about phone calls:" << endl;
	while (inFile.read((char*)&note, sizeof(note))) {
		cout << endl << note.number << " " << note.starth << ":" << note.startm << " " << note.endh << ":" << note.endm;
	}
	cout << endl;
	inFile.close();
}

void price() {
	ifstream mainFile;
	ofstream helpFile;
	mainFile.open("text.txt", ios::binary);
	helpFile.open("second.txt", ios::binary);
	logs note;
	double price;
	int length;
	int j = 1;
	int times, timef;        //timestart,  timefinish

	while (mainFile.read((char*)&note, sizeof(note))) {
		times = note.starth * 60 + note.startm;
		timef = note.endh * 60 + note.endm;
		if (times > timef) {
			timef = timef + 1440;
		}
		int i = 0;
		bool finished = false;
		price = 0;
		while (!finished) {
			if (times == timef) {
				length = i;
				if (length >= 3) {
					helpFile.write((char*)&note, sizeof(note));
				}
				cout << endl << "Price for phone " << j << " is: " << price;
				cout << endl << "Length for phone " << j << " is " << length;
				finished = true;
				j++;

			}
			else {
				if (times >= 540 && times <= 1200) {
					price = price + 1.5;
				}
				else if (times > 1200 && times < 1980) {
					price = price + 0.9;
				}
				if (times <= 540 && times >= 0) {
					price = price + 0.9;
				}
				else if (times >= 1980 && times <= 2640) {
					price = price + 1.5;
				}
				times++;
				i++;
			}

		}
	}
	cout << endl;
	mainFile.close();
	helpFile.close();
}

void copy() {
	ofstream mainFile;
	ifstream helpFile;
	logs note;
	mainFile.open("text.txt", ios::binary);
	helpFile.open("second.txt", ios::binary);
	while (helpFile.read((char*)&note, sizeof(note))) {
		mainFile.write((char*)&note, sizeof(note));
	}
	mainFile.close();
	helpFile.close();
}