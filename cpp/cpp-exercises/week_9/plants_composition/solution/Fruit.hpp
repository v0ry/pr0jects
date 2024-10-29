#pragma once

#include <string>

class Fruit
{
  public:
    /**
    /// @brief Construct a new Fruit object
    /// 
    /// @param description : Description of the fruit
    */
    Fruit(std::string description);

    /**
    /// @brief Get the Description object
    /// 
    /// @return const std::string Description of the fruit
     */
    const std::string getDescription() const;

  private:
    std::string description_;
};