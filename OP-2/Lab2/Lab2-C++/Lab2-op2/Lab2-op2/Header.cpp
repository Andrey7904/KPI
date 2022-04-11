#include "Header.h"

void create() {
	int n, x, y, z, rad;
	cout << "How many spheres do you want? "; cin >> n;
	vector <Sphere>v1(n);
	for (int i = 0; i < n; i++) {
		cout << "Enter x,y,z of center of sphere and its radius: " << endl;
		cout << "x="; cin >> x;
		cout << "y="; cin >> y;
		cout << "z="; cin >> z;
		cout << "rad="; cin >> rad;
		v1[i].setdata(x, y, z, rad);
	}
	cout << endl << "Spheres are: ";
	for (int i = 0; i < n; i++) {
		v1[i].printsp();
	}
	belong(v1, n);
}

void belong(vector<Sphere> v1, int n) {
	int a, b, c, j;
	cout << endl << endl << "Enter x,y,z of point: " << endl;
	cout << "x="; cin >> a;
	cout << "y="; cin >> b;
	cout << "z="; cin >> c;
	cout << endl;
	for (int i = 0; i < n; i++) {
		j = v1[i].pointsp(a, b, c);
		if (j == 1) {
			cout << "Point (" << a << ";" << b << ";" << c << ") belongs to sphere " << i + 1 << endl;
		}
	}
}