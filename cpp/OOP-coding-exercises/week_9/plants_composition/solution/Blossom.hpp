#pragma once

#include <string>

class Blossom
{
  public:

    /**
    /// @brief Construct a new Blossom object
    /// 
    /// @param colour Colour of the blossoms
     */
    Blossom(std::string colour);

    /**
    /// @brief Get the Colour object
    /// 
    /// @return const std::string colour of the blossom
     */
    const std::string getColour() const;

  private:
    std::string colour_;
};