#include "Database.hpp"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

using std::cout;
using std::endl;

int main()
{
    Database database("Studierendenstatistik.csv");
    database.majorWithMostStudents();
    database.majorWithMostFemaleStudents();
    database.majorWithLowestFemaleMaleRatio(50);
    database.majorWithHighestFemaleMaleRatio(50);
    database.majorWithHighestInternationalRatio(50);
    return 0;
}