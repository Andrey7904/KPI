#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");      //Підключаємо для підтримки кирилиці

	double x;
	double fact = 1;                   //факторіал
	double sum;                      
	double sum_result = 1;             
	int n = 1;                      //порядковий номер члена послідовності
	double eps = 0.0001;            //точність

	cout << "Enter x[0;5] x=";           
	cin >> x;
	if (x != 0)
	{
		do {
			fact *= (2 * n - 1) * 2 * n;                           //Знаходження факторіала
			sum = (pow(-1, n) * pow(x, (2 * n)) / fact);           //Знаходження sum
			if (n % 2 == 0)                                        //Перевірка на парність
			{
				sum_result += sum;
				cout << "Sum is=" << sum_result << endl;
			}
			n += 1;
		} while (abs(sum) > 0.0001);                      //Перевірка точності
	}
	cout << "Result = " << sum_result << endl;             //Вивід кінцевого результату
}

