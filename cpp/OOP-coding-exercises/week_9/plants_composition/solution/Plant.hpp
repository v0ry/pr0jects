#pragma once

#include <string>
#include <memory>

#include "Blossom.hpp"
#include "Fruit.hpp"
#include "GrowthBehaviour.hpp"

// class GrowthBehaviour;

class Plant 
{
  public:
    Plant(std::string name, GrowthBehaviour* growth_behaviour, Blossom blossom, Fruit fruit);

    /**
    /// @brief Water your plant so it can grow. Will change it's size depending on the plant.
    /// 
    /// @param amount_of_water added to plant
     */
    void waterPlant(int amount_of_water) const;

    /**
    /// @brief Prints all information about the plant. (Name, size, growth behaviour, blossoms, fruits)
    /// 
     */
    void showDescription() const;
  
  
  private:

    std::string name_;

    GrowthBehaviour* growth_behaviour_;

    Blossom blossom_;

    Fruit fruit_;

};