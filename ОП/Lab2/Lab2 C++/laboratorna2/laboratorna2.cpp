#include <iostream>
#include <math.h>
using namespace std;
int main()

{
	double x;
	double y;

	cout << "Type in x:";
	cin >> x;

	cout << "Type in y:";
	cin >> y;

	if (pow(x-1, 2) + pow(y, 2) <= 4 && -1 <= x && x <= 1) {
		cout << "Point (x,y) belongs to figure";
	}

	else if (abs(y) <= 3-x  && 1 <= x && x <= 3) {
		cout << "Point (x,y) belongs to figure";
	}

	else { cout << "Point (x,y) DOESN`T belong to figure"; }

}