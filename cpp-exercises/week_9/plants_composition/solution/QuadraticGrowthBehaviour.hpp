#pragma once

#include "GrowthBehaviour.hpp"

class QuadraticGrowthBehaviour : public GrowthBehaviour
{
  public:

    /**
    /// @brief Construct a new QuadraticGrowthBehaviour object
    /// 
     */
    QuadraticGrowthBehaviour();

    ~QuadraticGrowthBehaviour() override {};
    /**
    /// @brief Increases the size of the plant by amount_of_water^2
    /// 
    /// @param amount_of_water 
     */
    virtual void addWater(int amount_of_water) override;

};
