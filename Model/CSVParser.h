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
/**
* The CSVParser takes data from a file for a specific format ("lastName","firstName",CLASSIFICATION,GRADE)
* @author CodyVollrath
*/
class CSVParser
{
    public:
        /**
        * Creates an instance of the CSVParser class
        */
        CSVParser();

        /**
        * Destroys the CSVParser instance
        */
        virtual ~CSVParser();

        /**
        * Returns a list of students as a vector
        * @param csvData the data from the file
        * @return the students from the file
        */
        vector<Student> addStudentsFromFile(const string& csvData) const;


    protected:

    private:
        Student::Classification getClassification(const string& classification) const;
};
}

#endif // CSVPARSER_H
