#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "InterlacedStudentList.h"
#include "Student.h"
#include "StudentNode.h"
#include "Utils.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace model
{
class CSVParser
{
    public:
        CSVParser();
        virtual ~CSVParser();
        vector<Student> getStudents(const string& csvData) const;

    protected:

    private:
        Student::Classification getClassification(const string& classification) const;
};
}

#endif // CSVPARSER_H
