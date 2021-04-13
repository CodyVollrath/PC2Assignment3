#include "InterlacedStudentList.h"
namespace model
{
InterlacedStudentList::InterlacedStudentList()
{
    this->nameHead = 0;
    this->classificationHead = 0;
    this->gradeHead = 0;
}

InterlacedStudentList::~InterlacedStudentList()
{
    if (this->nameHead) {
        delete this->nameHead;
    }
    if (this->classificationHead) {
        delete this->classificationHead;
    }
    if (this->gradeHead) {
        delete this->gradeHead;
    }
    this->nameHead = 0;
    this->classificationHead = 0;
    this->gradeHead = 0;
}

void InterlacedStudentList::insert(StudentNode* node)
{
    this->addNameNode(node);
    this->addClassificationNode(node);
    this->addGradeNode(node);
}

void InterlacedStudentList::addNameNode(StudentNode* node)
{
    if (!this->nameHead || this->nameHead->getStudent().getLastName().compare(node->getStudent().getLastName()) >= 0) {
        StudentNode* tmp = this->nameHead;
        node->setNextName(tmp);
        this->nameHead = node;
        return;
    }

    StudentNode* current = this->nameHead;
    while (current->getNextName() && current->getNextName()->getStudent().getLastName().compare(node->getStudent().getLastName()) < 0) {
        current = current->getNextName();
    }
    node->setNextName(current->getNextName());
    current->setNextName(node);
}

void InterlacedStudentList::addClassificationNode(StudentNode* node)
{
    if (!this->classificationHead || this->classificationHead->getStudent().getClassification() >= node->getStudent().getClassification()) {
        StudentNode* tmp = this->classificationHead;
        node->setNextClassification(tmp);
        this->classificationHead = node;
        return;
    }
    StudentNode* current = this->classificationHead;
    while (current->getNextClassification() && current->getNextClassification()->getStudent().getClassification() < node->getStudent().getClassification()) {
        current = current->getNextClassification();
    }
    node->setNextClassification(current->getNextClassification());
    current->setNextClassification(node);
}

void InterlacedStudentList::addGradeNode(StudentNode* node)
{
    if (!this->gradeHead || this->gradeHead->getStudent().getGrade() >= node->getStudent().getGrade()) {
        StudentNode* tmp = this->gradeHead;
        node->setNextGrade(tmp);
        this->gradeHead = node;
        return;
    }
    StudentNode* current = this->gradeHead;
    while (current->getNextGrade() && current->getNextGrade()->getStudent().getGrade() < node->getStudent().getGrade()) {
        current = current->getNextGrade();
    }
    node->setNextGrade(current->getNextGrade());
    current->setNextGrade(node);
}

string InterlacedStudentList::generateReport(int selectionNumber) const
{
    switch (selectionNumber){
        case 0: return this->getReportByLastName(this->nameHead);
        break;
        case 1: return this->getReportByLastNameDesc(this->nameHead);
        break;
        case 2: return this->getReportByClassification(this->classificationHead);
        break;
        case 3: return this->getReportByClassificationDesc(this->classificationHead);
        break;
        case 4: return this->getReportByGrade(this->gradeHead);
        break;
        case 5: return this->getReportByGradeDesc(this->gradeHead);
        default: return "";
        break;
    }
}

string InterlacedStudentList::getReportByLastName(StudentNode* node) const
{
    if (!node){
        return "";
    } else {
        Student student = node->getStudent();
        return student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n" + this->getReportByLastName(node->getNextName());
    }
}

string InterlacedStudentList::getReportByClassification(StudentNode* node) const
{
    if (!node){
        return "";
    } else {
        Student student = node->getStudent();
        return student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n" + this->getReportByClassification(node->getNextClassification());
    }
}

string InterlacedStudentList::getReportByGrade(StudentNode* node) const
{
    if (!node){
        return "";
    } else {
        Student student = node->getStudent();
        return student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n" + this->getReportByGrade(node->getNextGrade());
    }
}

string InterlacedStudentList::getReportByLastNameDesc(StudentNode* node) const
{
    if (!node) {
        return "";
    } else {
        string item = this->getReportByLastNameDesc(node->getNextName());
        Student student = node->getStudent();
        item += student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n";
        return item;
    }
}

string InterlacedStudentList::getReportByClassificationDesc(StudentNode* node) const
{
    if (!node) {
        return "";
    } else {
        string item = this->getReportByClassificationDesc(node->getNextClassification());
        Student student = node->getStudent();
        item += student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n";
        return item;
    }
}

string InterlacedStudentList::getReportByGradeDesc(StudentNode* node) const
{
    if (!node) {
        return "";
    } else {
        string item = this->getReportByGradeDesc(node->getNextGrade());
        Student student = node->getStudent();
        item += student.getFirstName() + " " + student.getLastName() + " " + to_string(student.getClassification()) + " " +  to_string(student.getGrade()) + "\n";
        return item;
    }
}
}
