#include "SystemManager.h"
#include <fstream>
#pragma warning (disable:4996)

SystemManager::SystemManager() : count(0) 
{
}

SystemManager::~SystemManager()
{
    for (int i = 0; i < count; ++i)
        delete devices[i];
}

void SystemManager::registerDevice(BaseDevice* dev)
{
    if (count < MAX_DEVICES) {
        devices[count++] = dev;
    }
}

void SystemManager::simulateAll() 
{
    for (int i = 0; i < count; ++i) 
    {
        devices[i]->turnOn();
    }
}

void SystemManager::printAll() const 
{
    for (int i = 0; i < count; ++i) 
    {
        devices[i]->print();
    }
}

void SystemManager::saveToFile(const char* filename) const 
{
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write((char*)&count, sizeof(count));
}

void SystemManager::loadFromFile(const char* filename) 
{
    std::ifstream ifs(filename, std::ios::binary);
    int newCount;
    ifs.read((char*)&newCount, sizeof(newCount));
}