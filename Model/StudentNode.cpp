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
    if (this->nextNameStudentNode) {
        delete this->nextNameStudentNode;
    }

    this->nextNameStudentNode = 0;

    this->nextNameStudentNode = nextStudentNode;
}

}

