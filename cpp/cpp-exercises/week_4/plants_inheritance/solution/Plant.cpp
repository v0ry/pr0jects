//
// Plant base class
// Created by Katrin S. (Tutor)
//

#include "Plant.hpp"

Plant::Plant() : water_level_(0), NEEDED_WATER_(10) 
{

}

Plant::Plant(int needed_water) : water_level_(0), NEEDED_WATER_(needed_water) 
{

}

void Plant::waterPlant(int amount_of_water)
{
  water_level_ += amount_of_water;

  if (water_level_ > NEEDED_WATER_)
  {
    std::cout << "  Thank you for watering me." << std::endl;
  }
}
