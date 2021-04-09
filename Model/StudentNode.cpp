#include "StudentNode.h"
namespace model
{
StudentNode::StudentNode(Student* student)
{
    this->currentStudent = student;
}

StudentNode::~StudentNode()
{
    //dtor
}
}

