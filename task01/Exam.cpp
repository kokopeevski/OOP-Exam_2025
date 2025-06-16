// Exam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SystemManager.h"
#include "SmartModule.h"

int main() {
    SystemManager manager;

    SmartModule* mod1 = new SmartModule("SM001", "alarm123", 30.0);
    SmartModule* mod2 = new SmartModule("SM002", "secure456", 60.0);

    manager.registerDevice(mod1);
    manager.registerDevice(mod2);

    mod1->simulate(45.0);
    mod2->simulate(50.0);

    std::cout << "Condition of devices is:\n";
    manager.printAll();

    manager.saveToFile("devices.dat");

    return 0;
}