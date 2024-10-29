#include <iostream>

#include "Plant.hpp"
#include "Blossom.hpp"
#include "Fruit.hpp"
#include "NoGrowthBehaviour.hpp"
#include "QuadraticGrowthBehaviour.hpp"

int main()
{

  GrowthBehaviour *quad_growth_ptr{new NoGrowthBehaviour(100)};
  Plant plastic_plant{"plastic banana tree", quad_growth_ptr, Blossom("invisible"), Fruit("fake bananas")};
  std::cout << "Before watering:" << std::endl;
  plastic_plant.showDescription();
  plastic_plant.waterPlant(100);
  std::cout << "After watering:" << std::endl;
  plastic_plant.showDescription();

  GrowthBehaviour *no_growth_ptr{new QuadraticGrowthBehaviour()};
  Plant monster_plant{"monster apple tree", no_growth_ptr, Blossom("red"), Fruit("monstrous apples")};
  std::cout << std::endl
            << "Before watering:" << std::endl;
  monster_plant.showDescription();
  monster_plant.waterPlant(100);
  std::cout << "After watering:" << std::endl;
  monster_plant.showDescription();

  delete quad_growth_ptr;
  delete no_growth_ptr;
  return 0;
}
