#include "Header.h"

void print(string s) {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}
	cout << endl;
}

void editing(ifstream& inFile) {
	///// Дізнаємось кількість речень по кількості точок.
	string s2;
	int count = 0;
	while (!inFile.eof()) {
		getline(inFile, s2, char(46));
		count++;
	}
	count--;
	inFile.close();
	inFile.open("text.txt");
	string s1;
	vector<string>sentences(count);
	for (int i = 0; i < count; i++) {
		getline(inFile, s1, char(46));
		sentences[i] = s1;
	}

	for (int i = 0; i < sentences.size(); i++) {

		if (sentences[i][sentences[i].size() - 1] != '.') {
			sentences[i].push_back('.');
		}
		for (int j = 0; j < sentences[i].size() - 1; j++) {
			if (sentences[i][j] == '\n') {
				sentences[i].replace(j, 1, " ");
			}

		}
		if (sentences[i][0] == ' ') {
			sentences[i].erase(0, 1);
		}

	}

	cout << endl << "Sentences are:" << endl;
	for (int i = 0; i < sentences.size(); i++) {
		cout << sentences[i] << endl;
	}
	///////Ділимо речення на слова////////////

	vector<string>min_word(sentences.size());

	for (int i = 0; i < sentences.size(); i++) {
		int index = 0;
		for (int j = 0; j < sentences[i].size(); j++) {
			if (sentences[i][j] == ' ' || sentences[i][j] == ',' || sentences[i][j] == ';' || sentences[i][j] == '.') {
				index++;
			}
		}
		vector<string>word(index);
		int slovo = 0;
		for (int j = 0; j < sentences[i].size(); j++) {

			if (sentences[i][j] == ' ' || sentences[i][j] == ',' || sentences[i][j] == ';' || sentences[i][j] == '.') {
				slovo++;
			}
			else {
				word[slovo].push_back(sentences[i][j]);
			}
		}
		string temp = word[0];
		for (int j = 0; j < word.size(); j++) {
			if (temp.size() > word[j].size()) {
				temp = word[j];
			}
		}
		min_word[i] = temp;
	}

	ofstream outFile2;
	outFile2.open("text2.txt");
	for (int i = 0; i < sentences.size(); i++) {
		outFile2 << sentences[i] << "--" << min_word[i].size() << "--" << min_word[i] << endl;
	}
	outFile2.close();
	ifstream inFile2;
	inFile2.open("text2.txt");
	string text;
	cout << endl << "Text is:" << endl;
	while (!inFile2.eof()) {
		getline(inFile2, text);
		print(text);
	}
}