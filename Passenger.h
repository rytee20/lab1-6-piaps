#pragma once
#include <iostream>
using namespace std;

class Passenger
{
public:
	Passenger() {
		cout << "Создан новый пассажир." << endl;
	}

	void info() {
		cout << "Пассажир." << endl;
	}
};