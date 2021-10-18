#include <iostream>

using namespace std;

int main() {

	double a;
	double x;
	int n;
	double y;             //y
	double yi;            //y(n)
	int i=0;              //counter

	cout << "Enter a,(a>0): ";
	cin >> a;
	cout << "Enter x,(x>0): ";
	cin >> x;
	cout << "Enter n,(n>=1): ";
	cin >> n;

	y = a;
	yi = a;
	
	for (i=0; i<n; i = i + 1) {
		yi = (1./2) * (y + x / y);
		y=yi;
	}
	cout << yi;

}
