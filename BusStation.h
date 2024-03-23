#pragma once
#include <vector>
#include "AbstractFactory.h"
//#include "CarsAndPeople.h"
using namespace std;

class BusStation {
public:

	vector<BoardAnyCars*> boardTaxi;
	vector<BoardAnyCars*> boardBus;
	vector<Driver*> driverTaxi;
	vector<Driver*> driverBus;
	vector<Passenger*> passengers;

	void info() {
		int i;
		for (i = 0; i < boardBus.size(); ++i) boardBus[i]->info();
		for (i = 0; i < boardTaxi.size(); ++i) boardTaxi[i]->info();
		for (i = 0; i < driverBus.size(); ++i) driverBus[i]->info();
		for (i = 0; i < driverTaxi.size(); ++i) driverTaxi[i]->info();
		for (i = 0; i < passengers.size(); ++i) passengers[i]->info();
	}

	BusStation() {}


	//PASSENGERS

	void addPassenger() {
		this->passengers.push_back(new Passenger());
	}

	void addPassengers(int amount) {
		for (int i = 0; i < amount; i++)
			this->addPassenger();
	}

	void deletePassenger(int iPass) {
		this->passengers.erase(passengers.begin() + iPass);
	}

	void deletePassengers(int amount) {
		this->passengers.erase(passengers.begin() + 0, passengers.begin() + amount);
	}


	//DRIVERS

	void addBusDriver(BusFactory& busFactory) {
		this->driverBus.push_back(busFactory.createDriver());
	}

	void addBusDrivers(BusFactory& busFactory, int amount) {
		for (int i = 0; i < amount; i++)
			this->addBusDriver(busFactory);
	}

	void addTaxiDriver(TaxiFactory& taxiFactory) {
		this->driverTaxi.push_back(taxiFactory.createDriver());
	}

	void addTaxiDrivers(TaxiFactory& taxiFactory, int amount) {
		for (int i = 0; i < amount; i++)
			this->addTaxiDriver(taxiFactory);
	}

	void deleteTaxiDriver(int iDriv) {
		this->driverTaxi.erase(driverTaxi.begin() + iDriv);
	}

	void deleteTaxiDrivers(int amount) {
		this->driverTaxi.erase(driverTaxi.begin() + 0, driverTaxi.begin() + amount);
	}

	void deleteBusDriver(int iDriv) {
		this->driverBus.erase(driverBus.begin() + iDriv);
	}

	void deleteBusDrivers(int amount) {
		this->driverBus.erase(driverBus.begin() + 0, driverBus.begin() + amount);
	}


	//BOARDS

	void addBusBoard(BusFactory& busFactory) {
		this->boardBus.push_back(busFactory.createBoard());
	}

	void addBusBoards(BusFactory& busFactory, int amount) {
		for (int i = 0; i < amount; i++)
			this->addBusBoard(busFactory);
	}

	void addTaxiBoard(TaxiFactory& taxiFactory) {
		this->boardTaxi.push_back(taxiFactory.createBoard());
	}

	void addTaxiBoards(TaxiFactory& taxiFactory, int amount) {
		for (int i = 0; i < amount; i++)
			this->addTaxiBoard(taxiFactory);
	}

	void deleteBusBoard(int iBus) {
		this->boardBus.erase(boardBus.begin() + iBus);
	}

	void deleteTaxiBoard(int iTaxi) {
		this->boardTaxi.erase(boardTaxi.begin() + iTaxi);
	}


	//BOARDING

	void boardPassengerToTaxi(int iTaxi, int iPass) {
		this->boardTaxi[iTaxi]->BoardPassenger(this->passengers[iPass]);
		this->deletePassenger(iTaxi);
	}

	void boardPassengersToTaxi(int iTaxi, int amount) {
		if (amount < 4)
			for (int i = 0; i < 3; i++)
				this->boardPassengerToTaxi(iTaxi,i);
	}

	void boardPassengerToBus(int iBus, int iPass) {
		this->boardBus[iBus]->BoardPassenger(this->passengers[iPass]);
		this->deletePassenger(iBus);
	}

	void boardPassengersToBus(int iBus, int amount) {
		if (amount < 30)
			for (int i = 0; i < 29; i++)
				this->boardPassengerToBus(iBus, i);
	}

	void boardDriverToTaxi(int iTaxi, int iDriv) {
		this->boardTaxi[iTaxi]->BoardDriver(this->driverTaxi[iDriv]);
		this->deleteTaxiDriver(iDriv);
	}

	void boardDriverToBus(int iBus, int iDriv) {
		this->boardBus[iBus]->BoardDriver(this->driverBus[iDriv]);
		this->deleteBusDriver(iDriv);
	}


	//ISREADY

	bool carIsReady(BoardAnyCars* boardAnyCars) {
		if (boardAnyCars->readyToDrive()) {
			cout << "Может ехать." << endl;

			return true;
		}
		else {
			cout << "Не может ехать." << endl;

			return false;
		}
	}


	~BusStation() {
		int i;
		for (i = 0; i < boardBus.size(); ++i) delete boardBus[i];
		for (i = 0; i < boardTaxi.size(); ++i) delete boardTaxi[i];
		for (i = 0; i < driverBus.size(); ++i) delete driverBus[i];
		for (i = 0; i < driverTaxi.size(); ++i) delete driverTaxi[i];
		for (i = 0; i < passengers.size(); ++i) delete passengers[i];
	}
};
