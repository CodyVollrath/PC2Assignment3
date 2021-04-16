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
    if (this->students) {
        delete this->students;
        this->students = new InterlacedStudentList();
    }
    FileLoader loader(fileName);
    string csvData = loader.loadFile();
    vector<Student> studentsList = this->parser->addStudentsFromFile(csvData);
    for (vector<Student>::size_type i = 0; i < studentsList.size(); i++) {
        StudentNode* node = new StudentNode(&studentsList.at(i));
        this->students->insert(node);
    }
}

void GradeLacerController::removeStudent(const string& firstName, const string& lastName)
{
    string fName = toUpperCase(firstName);
    string lName = toUpperCase(lastName);
    this->students->remove(fName,lName);
}

void GradeLacerController::addStudent(Student* student)
{
    this->students->insert(new StudentNode(student));
}

string GradeLacerController::getReport(int selectionNumber) const
{
    return this->students->generateReport(selectionNumber);
}

void GradeLacerController::writeDataToOutfile(const string& outfile, const string& data)
{
    if (outfile == "") {
        return;
    }
    FileSaver saver(outfile);
    saver.write(data);
}
}

