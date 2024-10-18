#include <iostream>

#include "Plant.hpp"


Plant::Plant(std::string name, GrowthBehaviour* growth_behaviour, Blossom blossom, Fruit fruit)
  : name_{name}, growth_behaviour_{growth_behaviour}, blossom_{blossom}, fruit_{fruit}
{
}


void Plant::waterPlant(int amount_of_water) const
{
  std::cout << "Watering the " << name_ << " with " << amount_of_water << " ml." << std::endl;
  growth_behaviour_->addWater(amount_of_water);
}


void Plant::showDescription() const
{
  std::cout << "The " << name_ << " is " << growth_behaviour_->getSize() << " cm tall, has "
            << growth_behaviour_->getDescription() << " growth, " << blossom_.getColour()
            << " blossoms and grows " << fruit_.getDescription() << "." << std::endl;
}
