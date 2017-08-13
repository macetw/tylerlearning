#include <QDate>
#include <QStringList>
#include <iostream>

using std::cout;
using std::endl;

static const unsigned int grades[4] = { 1, 2, 5, 8 };
static const QStringList kids = QStringList() << "A" << "E" << "K" << "S";
static const QStringList gradeNames = QStringList() << "Kindergarten"
                                                    << "First Grade"
                                                    << "Second Grade"
                                                    << "Third Grade"
                                                    << "Fourth Grade"
                                                    << "Fifth Grade"
                                                    << "Sixth Grade"
                                                    << "Seventh Grade"
                                                    << "Eighth Grade"
                                                    << "Freshman High School"
                                                    << "Sophomore High School"
                                                    << "Junior High School"
                                                    << "Senior High School"
                                                    << "Freshman College"
                                                    << "Sophomore College"
                                                    << "Junior College"
                                                    << "Senior College"
                                                    << "Graduated";


int main(int, char**)
{
    QDate today; //(2030, 10,1);
    QDate startOfSchool( 2017, 9, 1 );
    QDate startOfSummer( 2018, 6, 7 );
    unsigned int addYears = 0;

    while( today > startOfSummer ) {
        addYears++;
        startOfSchool = startOfSchool.addYears(1);
        startOfSummer = startOfSummer.addYears(1);
    }

    if (startOfSchool > today) {
        cout << "In September, kids will be entering:" << endl;
    } else {
        cout << "Kids are in:" << endl;
    }
    for (int i = 0; i < 4; i++) {
        unsigned int gradeIdx = grades[i]+addYears;
        if (gradeIdx >= gradeNames.size()) gradeIdx = gradeNames.size()-1;
        cout << gradeNames[gradeIdx].toStdString()
             << " for " << kids[i].toStdString() << endl;
    }
    return 0;
}


