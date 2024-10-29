#include "NoGrowthBehaviour.hpp"

NoGrowthBehaviour::NoGrowthBehaviour(int fixed_size) : GrowthBehaviour("no")
{
  size_ = fixed_size;
}

void NoGrowthBehaviour::addWater(int amount_of_water)
{
  int suppress_compiler_warning = amount_of_water;
  amount_of_water = suppress_compiler_warning;

  return;
}