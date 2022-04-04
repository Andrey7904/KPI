#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct logs {
	char number[50];
	int starth;
	int startm;
	int endh;
	int endm;
};

void create_note();
void printing();
void price();
void copy();