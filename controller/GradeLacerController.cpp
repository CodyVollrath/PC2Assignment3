#include "GradeLacerController.h"

namespace controller
{
GradeLacerController::GradeLacerController()
{
    this->parser = new CSVParser();
    this->students = 0;
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

void GradeLacerController::createStudentCollection(const string& fileName) const
{
    FileLoader loader(fileName);
    string csvData = loader.loadFile();
    vector<Student> values(this->parser->getStudents(csvData));
}
}

