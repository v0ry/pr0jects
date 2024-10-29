#include "QuadraticGrowthBehaviour.hpp"

QuadraticGrowthBehaviour::QuadraticGrowthBehaviour() : GrowthBehaviour("quadratic")
{
}


void QuadraticGrowthBehaviour::addWater(int amount_of_water)
{
  size_ += amount_of_water * amount_of_water; // You could also use pow(amount_of_water, 2)
}