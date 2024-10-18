#include <vector>
#include <iostream>
#include "Addition.hpp"
#include "Subtraction.hpp"


using std::vector;
using std::cout;
using std::endl;

int main()
{
  vector<int> a = {4, 5, 6};
  vector<int> b = {1, 2, 3};
  vector<Calculation*> calculations = {};

  //creating calculations and adding them to a vector
  for(int i = 0; i < (int)a.size(); i++)
  {
    Addition* addition = new Addition(a[i], b[i]);
    calculations.push_back(addition);
    Subtraction* subtraction = new Subtraction(a[i], b[i]);
    calculations.push_back(subtraction);
  }

  cout << "--Results--" << endl;
  //calculating the results
  for(int i = 0; i < (int)calculations.size(); i++)
  {
    int result = calculations[i]->calculate();
    cout << calculations[i]->getA() << " " << calculations[i]->getOperatorSymbol() << " " << calculations[i]->getB()
         << " = " << result << endl;
  }

  //deleting the calculation objects
  for(int i = 0; i < (int)calculations.size(); i++)
  {
    delete calculations[i];
  }

  return 0;
}