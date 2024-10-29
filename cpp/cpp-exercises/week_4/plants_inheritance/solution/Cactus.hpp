//
// Cactus class - derived class from Plant
// Created by Katrin S. (Tutor)
//

#ifndef CACTUS_HPP
#define CACTUS_HPP

#include <iostream>
#include "Plant.hpp"

class Cactus : public Plant
{
  private:
    static const int ALLOWED_WATER_LEVEL_ = 1;
    
  public:
    // constructor
    Cactus() : Plant{0} {};

    // destructor
    ~Cactus() override {};

    // virtual function for watering a plant (overwrites function in base class)
    void waterPlant(int amount_of_water) override;
};


#endif //CACTUS_HPP
