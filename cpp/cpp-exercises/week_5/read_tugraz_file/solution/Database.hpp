#ifndef DATABASE_HPP
#define DATABASE_HPP


#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Major.hpp"

using std::vector;


class Database
{
  vector<const Major*> majors_;
  const Major& maxNumber(STUDENT_GROUP group, unsigned min_n_students) const;
  const Major& maxRatio(STUDENT_GROUP group, unsigned min_n_students) const;
  void parseFile(const string& filename);  
  unsigned parseNumberString(const string& number_string);

  public:
    Database(string filename) { parseFile(filename); }
    
    Database(const Database& other) = delete;
    
    virtual ~Database();

    void majorWithMostStudents();
    void majorWithMostFemaleStudents();
    void majorWithLowestFemaleMaleRatio(unsigned min_n_students);
    void majorWithHighestFemaleMaleRatio(unsigned min_n_students);
    void majorWithHighestInternationalRatio(unsigned min_n_students);
    // feel free to add more/different search queries! :)

};


#endif // DATABASE_HPP