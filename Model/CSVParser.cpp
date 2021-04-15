#include "CSVParser.h"
namespace model
{
CSVParser::CSVParser()
{
    this->students = 0;
}

CSVParser::~CSVParser()
{
    if (this->students) {
        delete this->students;
    }
    this->students = 0;
}
vector<Student>* CSVParser::getStudents()
{
    return this->students;
}
void CSVParser::addStudentsFromFile(const string& csvData)
{
    if (this->students) {
        delete this->students;
    }
    this->students = new vector<Student>();
    vector<string> lines = splitStr(csvData, "\n");
    for (vector<string>::size_type i = 0; i < lines.size()-1; i++) {
        vector<string> field = splitStr(lines[i], ",");

        string firstName = field[1];
        string lastName = field[0];

        string classificationStr = toUpperCase(field[2]);
        Student::Classification classification = this->getClassification(classificationStr);

        string gradeStr = field[3];
        int grade = stoi(gradeStr);
        Student student(firstName, lastName, classification, grade);
        this->students->push_back(student);
    }
}

Student::Classification CSVParser::getClassification(const string& classification) const
{
    string upperClass = toUpperCase(classification);
    if (upperClass == Student::DualEnrollment) {
            return Student::DUALENROLLMENT;
    }
    if (upperClass == Student::Grad) {
            return Student::GRAD;
    }
    if (upperClass == Student::Postdoc) {
        return Student::POSTDOC;
    }
    if (upperClass == Student::Undergrad) {
        return Student::UNDERGRAD;
    }
    return Student::UNKNOWN;
}
}

