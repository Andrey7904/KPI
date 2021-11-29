#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int inputArrayC(int C[], int const n);
void inputArrayF(int F[], int const n, int C[], int minus_sum);

int main() {

	int const n = 7;        //array size
	int C[n];
	int F[n];
	int minus_sum;                //arithmetic mean

	minus_sum = inputArrayC(C, n);              //generating array C[n] and calculating arithmetic mean

	inputArrayF(F, n, C, minus_sum);            //generating array F[n]
}

int inputArrayC(int C[], int const n) {
	int minus_var = 0;            //sum of minus vars
	int minus_sum;                //arithmetic mean
	int i;
	int j = 0;
	//srand(time(0));              //if random generation is needed - delete first two slashes

	for (i = 0; i < n; i++) {
		C[i] = rand() % 19 - 9;
		if (C[i] < 0) {
			minus_var = minus_var + C[i];
			j++;
		}
	}
	minus_sum = abs(minus_var / j);          //arithmetic mean

	return minus_sum;
}

void inputArrayF(int F[], int const n, int C[], int minus_sum) {

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			F[i] = C[i] * minus_sum;
			cout << F[i] << "\t";
		}
		else {
			F[i] = C[i];
			cout << F[i] << "\t";
		}
	}
}