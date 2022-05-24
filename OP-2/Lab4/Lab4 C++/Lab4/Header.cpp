#include "Header.h"

double point::distance(point& obj) {
	double distance;
	distance = sqrt(pow((obj.x - x), 2) + pow((obj.y - y), 2));
	return distance;
}

void point::print() {
	cout << endl << "Coordinates of the point are (" << x << ";" << y << ")";
}

void pointX::setCoordsT(int t) {
	x = x0 + a1 * sin(t);
	y = 0;
}

void pointXY::setCoordsT(int t) {
	x = x0 + a1 * sin(t);
	y = y0 + a2 * cos(t);
}

void max_distance() {
	int k, n;
	double x1, y1, x2, y2;
	cout << "Input k: "; cin >> k;
	cout << "Input n: "; cin >> n;
	vector<pointX>v1(k);
	vector<pointXY>v2(n);

	int t;
	double max_dist = 0;
	double dist = 0;
	cout << "Enter t="; cin >> t; cout << endl;
	point* p;

	for (int i = 0; i < k; i++) {
		p = &v1[i];
		p->setCoordsT(t); p->print();
	}
	for (int i = 0; i < n; i++) {
		p = &v2[i];
		p->setCoordsT(t); p->print();
	}
	for (int i = 0; i < k; i++) {
		p = &v1[i];
		for (int j = 0; j < k - 1; j++) {
			dist = p->distance(v1[j + 1]);
			if (dist > max_dist) {
				max_dist = dist;
				x1 = p->getx();
				y1 = p->gety();
				x2 = v1[j + 1].getx();
				y2 = v1[j + 1].gety();
			}
		}
		for (int j = 0; j < n; j++) {
			dist = p->distance(v2[j]);
			if (dist > max_dist) {
				max_dist = dist;
				x1 = p->getx();
				y1 = p->gety();
				x2 = v2[j].getx();
				y2 = v2[j].gety();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		p = &v2[i];
		for (int j = 0; j < n - 1; j++) {
			dist = p->distance(v2[j + 1]);
			if (dist > max_dist) {
				max_dist = dist;
				x1 = p->getx();
				y1 = p->gety();
				x2 = v2[j + 1].getx();
				y2 = v2[j + 1].gety();
			}
		}
	}
	cout << endl << "Max distance is=" << max_dist << " Between points with coords (" << x1 << ";" << y1 << ") and (" << x2 << ";" << y2 << ")";
}