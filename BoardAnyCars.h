#pragma once
#include <vector>
#include "Driver.h"
#include "Passenger.h"
using namespace std;

class BoardException {};
class NullException {};

class BoardAnyCars {
protected:
	Driver* driver = nullptr;
	int maxPassengeres = 1;
	std::vector<Passenger*> passengers;

public:

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		if (passengers.size() > maxPassengeres)
			return false;
		return true;
	}

	void BoardPassenger(Passenger* p)
	{
		if (p)
			passengers.push_back(p);
		else
			throw NullException();
	}

	void BoardDriver(Driver* d)
	{
		if (d)
			driver = d;
		else
			throw NullException();
	}

	void info() {
		cout << "�������." << endl;
	}

	~BoardAnyCars()
	{
		if (driver)
			delete driver;
		for (auto p : passengers)
			delete p;
	}
};

class BoardTaxi : public BoardAnyCars
{
public:
	BoardTaxi()
	{
		maxPassengeres = 3;
		cout << "������� � ����� �������." << endl;
	}

	void BoardTaxiDriver(Driver* d)
	{
		if (d)
			if ((*d).category == B) {
				driver = d;
				cout << "�������� ��� � �����." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void BoardPassenger(Passenger* p)
	{

		if (p)
			if (passengers.size() < maxPassengeres) {
				passengers.push_back(p);
				cout << "�������� ��� � �����." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void info() {
		cout << "������� � �����." << endl;
	}

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1 || passengers.size() < maxPassengeres)
			return false;
		return true;
	}

	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCars
{
public:
	BoardBus()
	{
		maxPassengeres = 29;
		cout << "������� � ������� �������." << endl;
	}

	void BoardBusDriver(Driver* d)
	{
		if (d)
			if ((*d).category == D) {
				driver = d;
				cout << "�������� ��� � �������." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void BoardPassenger(Passenger* p)
	{

		if (p)
			if (passengers.size() < maxPassengeres) {
				passengers.push_back(p);
				cout << "�������� ��� � �������." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void info() {
		cout << "������� � �������." << endl;
	}

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1 || passengers.size() > maxPassengeres)
			return false;
		return true;
	}

	~BoardBus() {};
};