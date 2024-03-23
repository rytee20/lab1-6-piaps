#pragma once
#include <iostream>
using namespace std;

enum Category {D, B};

class Driver {
public:
	Category category;

	Driver() {};

	void info() {
		cout << "Водитель." << endl;
	}
};

class BusDriver : public Driver {
public:
	BusDriver() {
		category = D;
		cout << "Создан новый водитель автобуса." << endl;
	}

	void info() {
		cout << "Водитель автобуса." << endl;
	}
};

class TaxiDriver : public Driver {
public:
	TaxiDriver() {
		category = B;
		cout << "Создан новый водитель такси." << endl;
	}

	void info() {
		cout << "Водитель такси." << endl;
	}
};
