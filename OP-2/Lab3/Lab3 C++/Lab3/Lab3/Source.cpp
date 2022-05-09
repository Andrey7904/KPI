#include "Header.h"

int main() {
	bool flag;
	Number num1;
	Number num2(2, 2, 2, 2);
	int thou1, hund1, dec1, one1;
	cout << "Enter number`s categories." << endl << "Thousands:"; cin >> thou1;
	cout << "Hundreds:"; cin >> hund1;
	cout << "Decimals:"; cin >> dec1;
	cout << "Ones:"; cin >> one1;
	Number num3(one1, dec1, hund1, thou1);
	Number num4 = num3;

	cout << endl << "Number 1 is:"; num1.printnum(); 
	cout << endl << "Number 2 is:"; num2.printnum();
	cout << endl << "Number 3 is:"; num3.printnum();
	cout << endl << "Number 4 is:"; num4.printnum();
	
	++num1;
	--num2;
	num3 = num1 + num2;

	cout <<endl<< endl << "Number 1 is:"; num1.printnum();
	cout << endl << "Number 2 is:"; num2.printnum();
	cout << endl << "Number 3 is:"; num3.printnum();
	flag= num3 > num4;
	cout << endl<<endl;
	if (flag==true) {
		cout << "Number 3(" << num3.decimal() << ")is bigger than number 4(" << num4.decimal() << ")";
	}
	else {
		cout << "Number 4(" << num4.decimal() << ")is bigger than number 3(" << num3.decimal() << ")"; 
	}
	cout << endl;
}