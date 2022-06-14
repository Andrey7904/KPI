#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

struct Detail {
	string detail;
	int amount;
	string provider;
	Detail* left;
	Detail* right;
	void print_detail();
	Detail(){
		detail = "";
		amount = 0;
		provider = "";
		left = 0;
		right = 0;
	}
};

void add_detail(Detail* &newOne, Detail* &current);

void print_tree(Detail*& current);

void biggest_provider(Detail*& current, vector<int>&detailamount,int& i, vector<string>& providers);