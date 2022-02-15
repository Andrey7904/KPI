#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream outFile;
	outFile.open("text.txt");
	string s;
	cout << "Enter your text: (press CTRL + S  to stop)" << endl;
	getline(cin,s,char(19));
	outFile << s;
	outFile.close();
	cout << endl << "Text is:" << endl;
	print(s);
	/////¬в≥д в файл завершено, починаЇмо в файл≥ шукати р€дки./////////
	ifstream inFile;
	inFile.open("text.txt");
	editing(inFile);
}