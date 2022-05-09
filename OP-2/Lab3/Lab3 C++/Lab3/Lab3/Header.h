#pragma once
#include <iostream>
using namespace std;

class Number {
	int one;
	int dec;
	int hund;
	int thou;
public:
	int getOne() { return one; }
	int getDec() { return dec; }
	int getHund() { return hund; }
	int getThou() { return thou; }
	Number() { one = 1; dec = 1; hund = 1; thou = 1; }    //�� �������������
	Number(int one1, int dec1, int hund1, int thou1);           //� �����������
	Number(const Number& obj);           //����������� ���������
	int decimal();          //���������� ����������� ������� �����
	Number operator++();
	Number operator--();
	Number operator+(const Number num);
	bool operator>(Number num);
	void printnum();
};