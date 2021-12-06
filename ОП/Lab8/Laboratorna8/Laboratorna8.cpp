#include <iostream>
#include <ctime>

using namespace std;

float** initMatrix(int& size);
void outputMatrix(float **mx, int size);

int main()
{
	float** matrix; 
	int size;
	//srand(time(0));
	matrix = initMatrix(size);
	outputMatrix(matrix, size);
}

float** initMatrix(int& size) {
	float x;                                    //змінна для тримання 1го елементу минулого рядка 
	cout << "Enter size="; 
	cin >> size; 
	cout << endl;
	float **mx = new float *[size];                     //створюємо покажчик на двовимірний масив (в масиві покажчики на масиви)
	for (int i = 0; i < size; i++) {
		mx[i] = new float[size];                          //створюємо масиви
	}
	for (int j = 0; j < size; j++) {
		mx[0][j] = rand() % 10;                        //ініціалізуємо перший рядок 
	}
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mx[i][j] = mx[i - 1][j + 1];                   //задаємо наступні рядки
		}
		x = mx[i - 1][0];                                 //1й елемент попереднього рядка
		mx[i][size - 1] = x;                              //останній елемент поточного рядка = 1й попереднього
	}
	return mx;
}

void outputMatrix(float **mx, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << mx[i][j]<<"\t";
		}
		cout << endl;
	}
}