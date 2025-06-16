// Exam_task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConcreteMaterial.h"
#include "DynamicContainer.hpp"

int main() 
{
    try 
    {
        ConcreteMaterial m1("A101", 3);
        ConcreteMaterial m2("B202", 5);
        ConcreteMaterial m3("C303", 2);

        DynamicContainer<Material> c1;
        c1.add(m1);
        c1.add(m2);

        DynamicContainer<Material> c2;
        c2.add(m3);

        std::cout << c1;
        std::cout << c2;

        DynamicContainer<Material> c3 = c1 + c2;
        std::cout << "After merging:" << std::endl << c3;

        std::cout << "Accessing item 5 (invalid):" << std::endl;
        std::cout << c3[5]; // should throw
    }
    catch (const std::out_of_range& ex) {
        ex.what();
    }

    return 0;
}