#include "StudentNode.h"
namespace model
{
StudentNode::StudentNode(Student* student)
{
    this->currentStudent = new Student(student->getFirstName(), student->getLastName(), student->getClassification(), student->getGrade());
    this->nextNameStudentNode = 0;
    this->nextClassificationStudentNode = 0;
    this->nextGradeStudentNode = 0;
}

StudentNode::~StudentNode()
{
    if (this->currentStudent) {
        delete this->currentStudent;
    }
    this->currentStudent = 0;
}

StudentNode* StudentNode::getNextName() const
{
    return this->nextNameStudentNode;
}

StudentNode* StudentNode::getNextClassification() const
{
    return this->nextClassificationStudentNode;
}

StudentNode* StudentNode::getNextGrade() const
{
    return this->nextGradeStudentNode;
}

void StudentNode::setNextName(StudentNode* nextStudentNode)
{
    this->nextNameStudentNode = nextStudentNode;
}

void StudentNode::setNextClassification(StudentNode* nextStudentNode)
{
    this->nextClassificationStudentNode = nextStudentNode;
}

void StudentNode::setNextGrade(StudentNode* nextStudentNode)
{
    this->nextGradeStudentNode = nextStudentNode;
}

Student* StudentNode::getStudent() const
{
    return this->currentStudent;
}

int StudentNode::compareLastName(StudentNode* other) const
{
    if (!other) {
        return -2;
    }
    return this->currentStudent->getLastName().compare(other->getStudent()->getLastName());

}
int StudentNode::compareClassification(StudentNode* other) const
{
    if (!other) {
        return -2;
    }
    if (this->currentStudent->getClassification() > other->getStudent()->getClassification()) {
        return 1;
    } else if (this->currentStudent->getClassification() == other->getStudent()->getClassification()) {
        return 0;
    }
    return -1;
}
}

