#include "StudentNode.h"
namespace model
{
StudentNode::StudentNode(Student* student)
{
    this->currentStudent = student;
    this->nextNameStudentNode = 0;
}

StudentNode::~StudentNode()
{
    //dtor
}

StudentNode* StudentNode::getNext() const
{
    return this->nextNameStudentNode;
}

void StudentNode::setNext(StudentNode* nextStudentNode)
{
    this->nextNameStudentNode = nextStudentNode;
}

Student StudentNode::getStudent() const
{
    return *this->currentStudent;
}
}

