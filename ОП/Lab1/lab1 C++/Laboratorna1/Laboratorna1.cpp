// Laboratorna1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a;
    int n;
    int d;

    cout << "To calculate n element of arithmetic progression you need to enter a,n,d.\n";
    cout << "a="; cin >> a;
    cout << "n="; cin >> n;
    cout << "d="; cin >> d;

    int z= a + (n - 1) * d;  //z - n-ий елемент арифметичної прогресії 

    cout << "n element of arithmetic progression is:" << z;
}
