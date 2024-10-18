#include "GrowthBehaviour.hpp"

GrowthBehaviour::GrowthBehaviour(std::string description) : size_(0), description_(description)
{
}

int GrowthBehaviour::getSize() const
{
  return size_;
}

const std::string GrowthBehaviour::getDescription() const
{
  return description_;
}

// void GrowthBehaviour::addWater(int amount_of_water)
// {

// }