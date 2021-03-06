#include <iostream>
#include <cmath>
using namespace std;

double sqrt(double a, double k, int n);

int main() {
	double a;
	int n;
	cout << "Enter (a>0) a=";
	cin >> a;
	cout << "Enter n=";
	cin >> n;

	cout << "Result is: " << (sqrt(a, 3, n) - sqrt(a * a + 1, 6, n)) / (1 + sqrt(3 + a, 7, n));
	
}

double sqrt(double a, double k, int n) {
	int i;
	double y_n = a;                 //y0
	
	for (i = 1; i <= n; i = i+1) {
		y_n = (1 / k) * (a / (pow(y_n, k - 1)) + (k - 1) * y_n);
		
	}
	return y_n;              
}