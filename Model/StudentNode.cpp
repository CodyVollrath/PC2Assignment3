#include "StudentNode.h"
namespace model
{
StudentNode::StudentNode(Student* student)
{
    this->currentStudent = student;
    this->nextNameStudentNode = 0;
    this->nextClassificationStudentNode = 0;
    this->nextGradeStudentNode = 0;
}

StudentNode::~StudentNode()
{
    //dtor
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
}

