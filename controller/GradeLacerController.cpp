#include "GradeLacerController.h"

namespace controller
{
GradeLacerController::GradeLacerController()
{
    this->parser = new CSVParser();
    this->students = new InterlacedStudentList();

}

GradeLacerController::~GradeLacerController()
{
    if (this->parser) {
        delete this->parser;
    }
    if (this->students) {
        delete this->students;
    }

    this->parser = 0;
    this->students = 0;
}

void GradeLacerController::createStudentCollection(const string& fileName)
{
    FileLoader loader(fileName);
    string csvData = loader.loadFile();
    vector<Student> values(this->parser->getStudents(csvData));
    for (vector<Student>::size_type i = 0; i < values.size(); i++) {
        this->students->insert(new StudentNode(&values.at(i)));
    }
}

string GradeLacerController::getReport(int selectionNumber) const
{
    return this->students->generateReport(selectionNumber);
}

}

