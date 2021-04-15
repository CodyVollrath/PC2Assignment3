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
    this->parser->addStudentsFromFile(csvData);
    vector<Student>* students = this->parser->getStudents();
    for (vector<Student>::size_type i = 0; i < students->size(); i++) {
        StudentNode* node = new StudentNode(&students->at(i));
        this->students->insert(node);
    }
}

void GradeLacerController::removeStudent(const string& firstName, const string& lastName)
{
    string fName = toUpperCase(firstName);
    string lName = toUpperCase(lastName);
    this->students->remove(fName,lName);
}

string GradeLacerController::getReport(int selectionNumber) const
{
    return this->students->generateReport(selectionNumber);
}

void GradeLacerController::print() {
    return this->students->print();
}

}

