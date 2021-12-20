#include <string>
#include <iostream>

using namespace std;

string *split(string, string);
string *checker(string *, char, char, int);
int size_of(string *);
void output_arr(string *, int);

int main() {
    string s, delimiter = " ";
    char a, b;
    cout << "Input string: "; getline(cin, s);
    string *words = split(s, delimiter);
    cout << "Enter start letter: "; cin >> a;
    cout << "Enter finish letter: "; cin >> b;
    int size = size_of(words);
    string *end_array = checker(words, a, b, size); 
    size = size_of(end_array);
    cout << "All words, that starts with " << '"' << a << '"'  << " and finishes with " << '"' << b << '"' << ": " << endl;
    output_arr(end_array, size);
    delete[] words;
    delete[] end_array;
}

int size_of(string *words) {
    int size = 0;
    while (true) {
        if (isalpha(words[size][0])) {
            size++;
        } 
        else {
            break;
        }
    }
    return size;
}

void output_arr(string *p, int size) {
    for (int i = 0; i < size; i++) {
        cout << p[i] << endl;
    }
}

string *split(string s, string del) {

    string text = s + del;
    string *words = new string[20];
    int index = 0;

    int pos;
    string token;
    while ((pos = text.find(del)) != string::npos) {
        token = text.substr(0, pos);
        words[index] = token;
        text.erase(0, pos + del.length());
        index++;
    }

    return words;
}

string *checker(string *arr, char a, char b, int size) {
    string *result = new string[size];
    int index = 0;
    for (int i = 0; i < size; i++) {
        string st = arr[i];
        int l_in = st.length();
        if (l_in != 1) {
            char f = arr[i][0], s = arr[i][l_in - 1];
            if (f == a && s == b) {
                result[index] = st;
                index++;
            }
        }
    }
    return result;
}