#pragma once
#include <iostream>
#include <cmath>
#include<ctime>
#include <vector>

using namespace std;

class point {
protected:
	double x = 0, y = 0;
	int a1 = rand() % 5 + 1, a2 = rand() % 5 + 1, x0 = rand() % 5 + 1, y0 = rand() % 5 + 1;
public:
	double getx() { return x; }
	double gety() { return y; }
	virtual void setCoordsT(int t) = 0;
	double distance(point& obj);
	void print();
};

class pointX :public point {
public:
	void setCoordsT(int t);
};

class pointXY :public point {
public:
	void setCoordsT(int t);
};

void max_distance();