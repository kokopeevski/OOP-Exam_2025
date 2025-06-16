#pragma once
#include "Material.h"

class ConcreteMaterial : public Material 
{
public:
    ConcreteMaterial(const char* c, int level);
    void process() const override;
    Material* clone() const override;
    void print(std::ostream& os) const override;
};