#pragma once
#include "BoardAnyCars.h"
#include <iostream>

class AbstractFactory {
public:
	virtual Driver* createDriver() = 0;
	virtual BoardAnyCars* createBoard() = 0;
	virtual ~AbstractFactory() {}
};

class TaxiFactory : public AbstractFactory {
public:
	Driver* createDriver() override {
		return new TaxiDriver();
	}

	BoardAnyCars* createBoard() override {
		return new BoardTaxi();
	}
};

class BusFactory : public AbstractFactory {
public:
	Driver* createDriver() override {
		return new BusDriver();
	}

	BoardAnyCars* createBoard() override {
		return new BoardBus();
	}
};
