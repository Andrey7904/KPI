#include "Header.h"
#include "sphere.h"

int Sphere::pointsp(int a, int b, int c) {
	if (pow(x - a, 2) + pow(y - b, 2) + pow(z - c, 2) <= pow(rad, 2)) {
		return 1;
	}
	else {
		return 0;
	}
}