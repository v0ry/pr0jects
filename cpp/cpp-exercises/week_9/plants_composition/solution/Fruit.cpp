#include "Fruit.hpp"

Fruit::Fruit(std::string description) : description_(description)
{

}

const std::string Fruit::getDescription() const
{
  return description_;
}