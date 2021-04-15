#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>
using namespace std;

#include "Student.h"
using namespace model;

namespace outputformatter
{
class Formatter
{
    public:
        Formatter();
        virtual ~Formatter();
        string getReport(const vector<Student>& students) const;
    protected:

    private:
        string getClassification(int value) const;

};
}


#endif // FORMATTER_H
