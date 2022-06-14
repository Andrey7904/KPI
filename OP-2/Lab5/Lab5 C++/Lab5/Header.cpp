#include "Header.h"

void Detail::print_detail() {
	cout << endl << "Name: " << detail << "  Amount: " << amount << "  Provider: " << provider;
}

void add_detail(Detail* &newOne, Detail* &current) {
	Detail* p = new Detail;
	p = newOne;
	if (current) {
		if (p->detail > current->detail) {
			add_detail(newOne, current->right);
		}
		else if (p->detail < current->detail) {
			add_detail(newOne, current->left);
		}
	}
	else {
		current = newOne;
	}
}

void print_tree(Detail*& current) {
	Detail* p = new Detail;
	p = current;
	if (p) {
		p->print_detail();

		print_tree(p->left);
		print_tree(p->right);
	}
	else {
		
	}
}

void biggest_provider(Detail*& current, vector<int>&detailamount, int &i, vector<string>&providers) {
	Detail* p = new Detail;
	p = current;
	if (p) {
		providers[i]=p->provider;
		detailamount[i] = p->amount;
		i++;
		biggest_provider(p->left,detailamount,i,providers);
		biggest_provider(p->right, detailamount, i, providers);
	}
	else {

	}
}