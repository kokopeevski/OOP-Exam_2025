#include "ConcreteMaterial.h"

ConcreteMaterial::ConcreteMaterial(const char* c, int level) : Material(c, level)
{
}

void ConcreteMaterial::process() const 
{
    std::cout << "Processing material [" << code << "] with sensitivity level " << sensitivityLevel << std::endl;
}

Material* ConcreteMaterial::clone() const 
{
    return new ConcreteMaterial(*this);
}

void ConcreteMaterial::print(std::ostream& os) const 
{
    os << "Material Code: " << code << ", Sensitivity: " << sensitivityLevel;
}