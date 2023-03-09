#pragma once
#include <iostream>
#include <string>

using namespace std;

class People {
protected:
	char* man = new char[255];

public:
	People() {}
	People(char* name) : man{ name } {}
	~People() {man = nullptr;}
};


class Flat : public People {
protected:
	int numberFlat;
public:
	Flat() :numberFlat{ 0 } {}
	Flat(int num) :numberFlat{ num } {}
	~Flat() {numberFlat = 0;}
};


class Home : public Flat {
	int size = 0;
	int sizeMax = 20;
	int numberHome;
	int* allNumberHome = new int[sizeMax];
	int* allNumberFlat = new int[sizeMax];
	char** allName = new char* [sizeMax];


public:
	Home() :numberHome{ 0 } {}
	Home(char* namep, int numf, int numh) : numberHome{ numh } {
		Flat f{ numf };
		People p{ namep };
	}
	~Home() {
		numberHome = 0;
		delete[]allName;
		delete[]allNumberHome;
		delete[]allNumberFlat;
	}

	void Main() {
		int a = 1;
		while (a == 1) {
			cout << "write name: "; cin >> man;
			allName[size] = man;
			cout << "write number flat: "; cin >> numberFlat;
			allNumberFlat[size] = numberFlat;
			cout << "write number home: "; cin >> numberHome;
			allNumberHome[size] = numberHome;
			system("cls");
			cout << "do you want to add more residents?(1/0) "; cin >> a;
			if (a == 1)size++;
		}
		if (a == 0) show();
	}

	void show() {
		for (int i = 0; i <= size; i++) {
			cout << "Name: " << allName[i] << endl;
			cout << "Number Home: " << allNumberHome[i] << endl;
			cout << "Number Flat: " << allNumberFlat[i] << endl << endl;
		}
	}
};