#include <iostream>
#include "BusStation.h"
//#include "Singleton.h"
using namespace std;

//Singleton* Singleton::instance = nullptr;

int main()
{
    setlocale(LC_ALL, "RUS");

    BusStation* busStation = new BusStation;
    TaxiFactory taxiFactory;
    BusFactory busFactory;

    int counter = 0;

    //CarsAndPeople* cap = busStation.createBusStation(factory);

    //cout << "\nВывод:\n";
    //cap->info();
    //cout << "\n";

    busStation->addPassengers(40);

    busStation->addBusDrivers(busFactory,1);
    busStation->addBusBoards(busFactory, 1);

    busStation->addTaxiDrivers(taxiFactory, 4);
    busStation->addTaxiBoards(taxiFactory, 4);

    cout << "\nВывод:\n";
    busStation->info();
    cout << "\n";

    while ((!busStation->boardBus.empty() && !busStation->driverBus.empty()) 
        || (!busStation->boardTaxi.empty() && !busStation->driverTaxi.empty())) {

        if (!busStation->boardBus.empty() && !busStation->driverBus.empty()) {
            busStation->boardDriverToBus(0,0);

            for (int i = 0; i < 29; i++) {
                if (!busStation->passengers.empty()) busStation->boardPassengerToBus(0, 0);
                else break;
            }

            if (busStation->carIsReady(busStation->boardBus[0])) {
                busStation->deleteBusBoard(0);
            }
        }

        if (!busStation->boardTaxi.empty() && !busStation->driverTaxi.empty()) {
            busStation->boardDriverToTaxi(0, 0);

            for (int i = 0; i < 3; i++) {
                if (!busStation->passengers.empty()) busStation->boardPassengerToTaxi(0, 0);
                else break;
            }

            if (busStation->carIsReady(busStation->boardTaxi[0])) {
                busStation->deleteTaxiBoard(0);
            }
        }
    }

    cout << "\nВывод:\n";
    busStation->info();
    cout << "\n";

    /*cap = busStation.boardPassengerToTaxi(cap);
    cap = busStation.boardDriverToTaxi(cap);

    busStation.isReady(cap->ct[0]);

    cout << "\n";

    cap = busStation.addCarTaxi(cap, factory);
    busStation.isReady(cap->ct[1]);

    cout << "\nКласс одиночка:\n";
    Singleton* singletonInstance = Singleton::getInstance();
    singletonInstance->hi();*/

    return 0;
}
