/*#pragma once
#include <vector>
#include "AbstractFactory.h"
using namespace std;

class CarsAndPeople {
public:
	vector<BoardAnyCars*> boardTaxi;
	vector<BoardAnyCars*> boardBus;
	vector<Driver*> driverTaxi;
	vector<Driver*> driverBus;
	vector<Passenger*> p;

	void info() {
		int i;
		for (i = 0; i < boardBus.size(); ++i) boardBus[i]->info();
		for (i = 0; i < boardTaxi.size(); ++i) boardTaxi[i]->info();
		for (i = 0; i < driverBus.size(); ++i) driverBus[i]->info();
		for (i = 0; i < driverTaxi.size(); ++i) driverTaxi[i]->info();
		for (i = 0; i < p.size(); ++i) p[i]->info();
	}

	~CarsAndPeople() {
		int i;
		for (i = 0; i < boardBus.size(); ++i) delete boardBus[i];
		for (i = 0; i < boardTaxi.size(); ++i) delete boardTaxi[i];
		for (i = 0; i < driverBus.size(); ++i) delete driverBus[i];
		for (i = 0; i < driverTaxi.size(); ++i) delete driverTaxi[i];
		for (i = 0; i < p.size(); ++i) delete p[i];
	}
};*/
