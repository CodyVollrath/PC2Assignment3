#include "InterlacedStudentList.h"
namespace model
{
InterlacedStudentList::InterlacedStudentList()
{
    this->root = 0;
}

InterlacedStudentList::~InterlacedStudentList()
{
    if (this->root) {
        delete this->root;
    }
    this->root = 0;
}

void InterlacedStudentList::insert(StudentNode* node)
{
    this->addNameNode(node);
}

void InterlacedStudentList::print()
{
    this->printList(this->root);
}

void InterlacedStudentList::printList(StudentNode* node)
{
    if (node) {
        cout << node->getStudent().getFirstName() << " " << node->getStudent().getLastName() << endl;
        printList(node->getNext());
    }
}

void InterlacedStudentList::addNameNode(StudentNode* node)
{
    if (!this->root) {
        this->root = node;
        return;
    }

    StudentNode* currNode = this->root;

    string lastNameToBeAdded = node->getStudent().getLastName();
    string lastNameOfCurrentNode = currNode->getStudent().getLastName();

    if (lastNameToBeAdded.compare(lastNameOfCurrentNode) < 0) {
        this->swapNodes(node, currNode);
        return;
    }

    while (currNode->getNext()) {
        string lastNameOfNextNode = currNode->getNext()->getStudent().getLastName();
        if (lastNameToBeAdded.compare(lastNameOfNextNode) < 0) {
            this->swapNodes(node, currNode);
            return;

        } else {
            currNode = currNode->getNext();
        }
    }
    currNode->setNext(node);
}

void InterlacedStudentList::swapNodes(StudentNode* node1, StudentNode* node2)
{
    if (node2 == this->root) {
        StudentNode* tmp = node2;
        this->root = node1;
        this->root->setNext(tmp);
        return;
    }
    StudentNode* tmp = node2->getNext();
    node2->setNext(node1);
    node1->setNext(tmp);
}
}
