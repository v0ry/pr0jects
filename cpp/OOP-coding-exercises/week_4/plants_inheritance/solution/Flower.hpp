//
// Flower class - derived class from Plant
// Created by Katrin S. (Tutor)
//

#ifndef FLOWER_HPP
#define FLOWER_HPP

#include <iostream>
#include "Plant.hpp"

class Flower : public Plant
{
  private:
    bool blossom_;

  public:
    // constructor
    Flower() : Plant{}, blossom_{false} {};

    // destructor
    ~Flower() override {};

    // getter blossom_
    bool getBlossom() {return blossom_;};

    // setter blossom_
    void setBlossom(bool blossom) {blossom_ = blossom;};
};


#endif //FLOWER_HPP
