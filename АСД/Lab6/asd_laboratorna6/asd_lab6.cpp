#include <iostream>
using namespace std;

int function(int Num, int i);

int main()
{
	int num;
	int p;
	int i = -1;
	cout << "Enter number: ";
	cin >> num;

	p = function(num,i);
	cout << p << endl;
}

int function(int Num, int i)
{
	int t = 0;

	if (Num == 0) {                          //umova vyhodu
		return 0;
	}
	else
	{
		i++;
		t = (Num % 10) * (1 << i) + function(Num / 10, i);

		return t;
	}
}
