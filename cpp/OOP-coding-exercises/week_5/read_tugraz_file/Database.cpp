#include "Database.hpp"
#include <limits>
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::stoul;


Database::~Database()
{
  for (const Major* major : majors_)
  {
    delete major;
  }
};


void Database::parseFile(const string& filename)
{
  /* TODO:
  - Read in the csv file. For each line of the csv file:
    - Create an instance of the class `Major`.
      - The constructor of `Major` expects the pieces of information contained in the csv file.
    - `push_back` the created `Major` instance into the `majors_` attribute (an std::vector) of the database.
  - If you want, you can add more attributes or member functions to `Database` to help you solve the task.
  - Have fun! :)
  */
  
}


const Major& Database::maxNumber(STUDENT_GROUP group, unsigned min_n_students=0) const
{
  const Major* max{ nullptr };
  for (const Major* major : majors_)
  {
    if (major->numberOfStudents(STUDENT_GROUP::TOTAL) < min_n_students)
    {
      continue; // only majors with at least min_n_students students are considered
    }
    if (!max || (major->numberOfStudents(group) > max->numberOfStudents(group)))
    {
      max = major;
    }
  }
  return *max; // what happens if there were no majors in the `majors_` attribute?
}


const Major& Database::maxRatio(STUDENT_GROUP group, unsigned min_n_students=0) const
{
  const Major* max{ nullptr };
  for (const Major* major : majors_)
  {
    if (major->numberOfStudents(STUDENT_GROUP::TOTAL) < min_n_students)
    {
      continue; // only majors with at least min_n_students students are considered
    }
    if (!max || (major->ratioOfStudents(group) > max->ratioOfStudents(group)))
    {
      max = major;
    }
  }
  return *max; // what happens if there were no majors in the `majors_` attribute?
}


void Database::majorWithMostStudents()
{
  const Major& major = maxNumber(STUDENT_GROUP::TOTAL);
  
  cout << "Das Studium mit den meisten Studierenden an der TU Graz ist " << major.getName()
    << " mit " << major.numberOfStudents(STUDENT_GROUP::TOTAL) << " Studierenden." << endl;
}


void Database::majorWithMostFemaleStudents()
{
  const Major& major = maxNumber(STUDENT_GROUP::WOMEN_TOTAL);

  cout << "Das Studium mit den meisten Studentinnen an der TU Graz ist " << major.getName()
    << " mit " << major.numberOfStudents(STUDENT_GROUP::WOMEN_TOTAL) << " Studentinnen." << endl;
}


void Database::majorWithLowestFemaleMaleRatio(unsigned min_n_students) // only majors with at least min_n_students students are considered
{ 
  const Major& major = maxRatio(STUDENT_GROUP::MEN_TOTAL, min_n_students);

  cout << "Unter allen Studien an der TU Graz, die von mindestens " << min_n_students
    << " Studierenden studiert werden, ist " << major.getName() << " jenes mit dem geringsten Frauenanteil ("
    << std::fixed << std::setprecision(1) << major.ratioOfStudents(STUDENT_GROUP::WOMEN_TOTAL) * 100
    << " %)." << endl;
}


void Database::majorWithHighestFemaleMaleRatio(unsigned min_n_students)
{
  const Major& major = maxRatio(STUDENT_GROUP::WOMEN_TOTAL, min_n_students);

  cout << "Unter allen Studien an der TU Graz, die von mindestens " << min_n_students
    << " Studierenden studiert werden, ist " << major.getName() << " jenes mit dem hoechsten Frauenanteil ("
    << std::fixed << std::setprecision(1) << major.ratioOfStudents(STUDENT_GROUP::WOMEN_TOTAL) * 100
    << " %)." << endl;
}


void Database::majorWithHighestInternationalRatio(unsigned min_n_students)
{
  const Major& major = maxRatio(STUDENT_GROUP::INT_TOTAL, min_n_students);

  cout << "Unter allen Studien an der TU Graz, die von mindestens " << min_n_students
    << " Studierenden studiert werden, ist " << major.getName()
    << " jenes mit dem hoechsten Anteil an internationalen Studierenden ("
    << std::fixed << std::setprecision(1) << major.ratioOfStudents(STUDENT_GROUP::INT_TOTAL) * 100
    << " %)." << endl;
}
