//
// Plant project
// Created by Katrin S. (Tutor)
//

#include "Plant.hpp"
#include "Flower.hpp"
#include "Tree.hpp"
#include "Cactus.hpp"

#include <iostream>
#include <vector>


int main(void)
{
  // Plant my garden
  Plant plant1, plant2;
  Flower flower1, flower2;
  Cactus cactus1, cactus2;
  Tree tree1, tree2;

  std::vector<Plant*> plant_vector;
  plant_vector.push_back(&plant2);
  plant_vector.push_back(&flower2);
  plant_vector.push_back(&cactus2);
  plant_vector.push_back(&tree2);


  // Start watering my plants
  int volume_watering_can = 15;

  // 1) Water plants1
  std::cout << "Watering plant1:"<< std::endl;
  plant1.waterPlant(volume_watering_can);

  std::cout << "Watering flower1:"<< std::endl;
  flower1.waterPlant(volume_watering_can);

  std::cout << "Watering cactus1:"<< std::endl;
  cactus1.waterPlant(volume_watering_can);

  std::cout << "Watering tree1:"<< std::endl;
  tree1.waterPlant(volume_watering_can);


  // 2) Water plants from my plant_vector
  std::cout << std::endl;
  std::cout <<  "Watering plant2:"<< std::endl;
  plant_vector.at(0)->waterPlant(volume_watering_can);

  std::cout << "Watering flower2:"<< std::endl;
  plant_vector.at(1)->waterPlant(volume_watering_can);

  std::cout << "Watering cactus2:"<< std::endl;
  plant_vector.at(2)->waterPlant(volume_watering_can);

  std::cout << "Watering tree2:"<< std::endl;
  plant_vector.at(3)->waterPlant(volume_watering_can);

  // HINT: Think of what you need to do such that 1) and 2) result in the same behavior.

  return 0;
}
