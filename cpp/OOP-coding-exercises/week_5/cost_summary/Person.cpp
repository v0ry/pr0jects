//
// WG Costs overview
// Created by David K. (Tutor)
//

#include "Person.hpp"



void Person::readCosts()
{
  std::cout << "Add new costs for " << name_ << ":  (type 'exit' in description if finished)" << std::endl;
  while(1)
  {
    std::cout << "Description: ";
    std::string description;
//    std::cin >> description;
    getline(std::cin, description);
    if(isEqual(description, "exit"))
      break;
    std::cout << "Price: ";
    float price = 0.0;
    std::cin >> price;

    while (!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "[ERROR] Enter Price: ";
      std::cin >> price;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // TODO: create Cost object on heap and add the cost to the 'costs_'-vector of the person


  }
}


void Person::printCosts() const
{
  std::cout << "----------------------------------" << std::endl;
  std::cout << "Costs of " << name_ << std::endl;

  // TODO: call for each cost the print function


  std::cout << "Total costs of " << name_ << ": " << getFullCosts() << std::endl;
}



// taken form https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
// begin
bool Person::isEqual(const std::string& a, const std::string& b)
{
  return std::equal(a.begin(), a.end(),b.begin(), b.end(),[](char a, char b)
  {
    return tolower(a) == tolower(b);
  });
}
// end
