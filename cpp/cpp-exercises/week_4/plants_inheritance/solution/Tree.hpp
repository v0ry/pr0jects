//
// Tree class - derived class from Plant
// Created by Katrin S. (Tutor)
//

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "Plant.hpp"

class Tree : public Plant
{
  private:
    bool full_grown_;

  public:
    // constructor
    Tree() : Plant{}, full_grown_{false} {};

    // destructor
    ~Tree() override {};

    // getter full_grown_
    bool getFullGrown() {return full_grown_;};

    // setter full_grown_
    void setFullGrown() {full_grown_ = true;};
};


#endif //TREE_HPP
