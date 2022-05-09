#include "Header.h"

Number::Number(int one1, int dec1, int hund1, int thou1) {           //з параметрами
	one = one1; dec = dec1; hund = hund1; thou = thou1;
}

Number::Number(const Number& obj) {
	one = obj.one;
	dec = obj.dec;
	hund = obj.hund;
	thou = obj.thou;
}

int Number::decimal() {
	int num;
	num = thou * 1000 + hund * 100 + dec * 10 + one;
	return num;
}

Number Number::operator++() {
	++one; ++dec; ++hund; ++thou;
	return *this;
}
Number Number::operator--() {
	--one; --dec; --hund; --thou;
	return *this;
}

Number Number::operator+(const Number num) {
	Number temp(0, 0, 0, 0);
	temp.one = one + num.one;
	temp.dec = dec + num.dec;
	temp.hund = hund + num.hund;
	temp.thou = thou + num.thou;
	return temp;
}

bool Number::operator>(Number num) {
	if (decimal() > num.decimal()) {
		return true;
	}
	else {
		return false;
	}
}

void Number::printnum() {
	cout << endl << "Number by categories is: Thousands:" << thou << " Hundreds:" << hund << " Decimals:" << dec << " One:" << one << " Decimal form is: " << decimal();
}