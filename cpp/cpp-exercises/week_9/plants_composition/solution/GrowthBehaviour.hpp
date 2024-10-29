#pragma once

#include <string>

class GrowthBehaviour
{
  public:
    GrowthBehaviour(std::string description);
    virtual ~GrowthBehaviour() {};

    /**
    /// @brief Get the Size object
    ///
    /// @return int size of the plant
     */
    int getSize() const;

    /**
    /// @brief Get the Description object
    ///
    /// @return const std::string Growth description
     */
    const std::string getDescription() const;

    /**
    /// @brief Depending on the plant type it grows depending on the amount of water added.
    ///
    /// @param amount_of_water to add to plant
     */
    virtual void addWater(int amount_of_water) = 0;

  protected:
    int size_;

  private:
    std::string description_;

};