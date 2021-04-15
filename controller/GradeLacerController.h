#ifndef GRADELACERCONTROLLER_H
#define GRADELACERCONTROLLER_H
#include "Utils.h"
#include <string>
using namespace std;

#include "FileLoader.h"
#include "FileSaver.h"
using namespace datatier;

#include "CSVParser.h"
using namespace model;

#include "Formatter.h"
using namespace outputformatter;

namespace controller
{
class GradeLacerController
{
    public:
        GradeLacerController();
        virtual ~GradeLacerController();
        void createStudentCollection(const string& fileName);
        string getReport(int selectionNumber) const;
        void addStudent(Student* student);
        void removeStudent(const string& firstName, const string& lastName);
        void writeDataToOutfile(const string& outfile, const string& data);
        void clear();
    protected:

    private:
        CSVParser* parser;
        InterlacedStudentList* students;
        Formatter* outputFormatter;
        void generateReport();
};
}


#endif // GRADELACERCONTROLLER_H
