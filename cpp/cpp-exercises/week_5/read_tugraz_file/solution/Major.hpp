#ifndef MAJOR_HPP
#define MAJOR_HPP

#include <string>
#include <map>

using std::string;
using std::map;


enum class STUDENT_GROUP
{
  WOMEN_DOM, // female domestic students
  MEN_DOM, // male domestic 
  WOMEN_INT, // female international students
  MEN_INT,
  TOTAL,
  WOMEN_TOTAL,
  MEN_TOTAL,
  DOM_TOTAL,
  INT_TOTAL
};


class Major
{
  string id_;
  string name_;
  map<STUDENT_GROUP, unsigned> n_students_;

  public:
    Major(string major_id,
          string major_name,
          unsigned women_dom,
          unsigned men_dom,
          unsigned women_int,
          unsigned men_int,
          unsigned total);

    Major(const Major& other) = delete;

    virtual ~Major() {};

    string getName() const { return name_; }
    unsigned numberOfStudents(STUDENT_GROUP group) const { return n_students_.at(group); }
    double ratioOfStudents(STUDENT_GROUP group) const;
};


#endif // MAJOR_HPP