#pragma once

#include "GrowthBehaviour.hpp"

/**
/// @brief Plastic plant
/// 
 */
class NoGrowthBehaviour : public GrowthBehaviour
{
  public:

    /**
    /// @brief Construct a new NoGrowthBehaviour object
    /// 
    /// @param fixed_size Size of the plant
     */
    NoGrowthBehaviour(int fixed_size);

    ~NoGrowthBehaviour() override {};
    /**
    /// @brief Does nothing, plastic plants can't grow
    /// 
    /// @param amount_of_water added to the plant
     */
    virtual void addWater(int amount_of_water) override;
};