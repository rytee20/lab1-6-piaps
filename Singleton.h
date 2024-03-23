#pragma once
#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {}
    ~Singleton() {}

    static Singleton* instance;

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void hi() {
        cout << "������, ��� ����� Singleton!" << endl;
    }
};
