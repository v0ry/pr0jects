//
// Plant base class
// Created by Katrin S. (Tutor)
//

#ifndef PLANT_HPP
#define PLANT_HPP

#include <iostream>

class Plant
{
  protected:
    int water_level_;
    const int NEEDED_WATER_;

  public:
    // constructor
    Plant();
    Plant(int needed_water);

    // virtual destructor
    virtual ~Plant()  {};

    // virtual function for watering a plant (can be overwritten by derived classes)
    virtual void waterPlant(int amount_of_water); 
};


#endif //PLANT_HPP
