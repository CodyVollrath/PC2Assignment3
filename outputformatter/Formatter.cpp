#include "Formatter.h"
namespace outputformatter
{
Formatter::Formatter()
{

}

Formatter::~Formatter()
{
    //dtor
}

string Formatter::getReport(const vector<Student>& students) const
{
    string report = "";
    for (vector<Student>::size_type i = 0; i < students.size(); i++) {
        Student student = students.at(i);
        report += student.getFirstName() + "\n";
    }
    return report;
}

string Formatter::getClassification(int value) const
{
    return "";
}
}

