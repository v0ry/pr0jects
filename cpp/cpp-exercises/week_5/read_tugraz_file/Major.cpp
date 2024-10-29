#include "Major.hpp"


Major::Major(string major_id,
             string major_name,
             unsigned women_dom,
             unsigned men_dom,
             unsigned women_int,
             unsigned men_int,
             unsigned total)
  : id_{major_id},
    name_{major_name},
    n_students_{ // note that parentheses would not work here
      { STUDENT_GROUP::WOMEN_DOM,   women_dom             },
      { STUDENT_GROUP::MEN_DOM,     men_dom               },
      { STUDENT_GROUP::WOMEN_INT,   women_int             },
      { STUDENT_GROUP::MEN_INT,     men_int               },
      { STUDENT_GROUP::TOTAL,       total                 },
      { STUDENT_GROUP::WOMEN_TOTAL, women_dom + women_int },
      { STUDENT_GROUP::MEN_TOTAL,   men_dom + men_int     },
      { STUDENT_GROUP::DOM_TOTAL,   women_dom + men_dom   },
      { STUDENT_GROUP::INT_TOTAL,   women_int + men_int   }
    }
{
}


double Major::ratioOfStudents(STUDENT_GROUP group) const
{
  return n_students_.at(group) * 1.0 / n_students_.at(STUDENT_GROUP::TOTAL);
}
