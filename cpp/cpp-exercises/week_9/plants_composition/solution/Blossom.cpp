#include "Blossom.hpp"

Blossom::Blossom(std::string colour) : colour_(colour)
{

}

const std::string Blossom::getColour() const
{
  return colour_;
}