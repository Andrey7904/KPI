#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");      //ϳ�������� ��� �������� ��������

	double x;
	double fact = 1;                   //��������
	double sum;                      
	double sum_result = 1;             
	int n = 1;                      //���������� ����� ����� �����������
	double eps = 0.0001;            //�������

	cout << "Enter x[0;5] x=";           
	cin >> x;
	if (x != 0)
	{
		do {
			fact *= (2 * n - 1) * 2 * n;                           //����������� ���������
			sum = (pow(-1, n) * pow(x, (2 * n)) / fact);           //����������� sum
			if (n % 2 == 0)                                        //�������� �� �������
			{
				sum_result += sum;
				cout << "Sum is=" << sum_result << endl;
			}
			n += 1;
		} while (abs(sum) > 0.0001);                      //�������� �������
	}
	cout << "Result = " << sum_result << endl;             //���� �������� ����������
}

