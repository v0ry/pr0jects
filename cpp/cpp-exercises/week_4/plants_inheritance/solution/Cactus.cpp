//
// Cactus class - derived class from Plant
// Created by Katrin S. (Tutor)
//

#include "Cactus.hpp"

void Cactus::waterPlant(int amount_of_water)
{
  water_level_ += amount_of_water;

  if (water_level_ > ALLOWED_WATER_LEVEL_)
  {
    std::cout << "  Help I am drowning." << std::endl;
  }
}
