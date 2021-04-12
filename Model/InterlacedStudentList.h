#ifndef INTERLACEDSTUDENTLIST_H
#define INTERLACEDSTUDENTLIST_H
#include "Student.h"
#include "StudentNode.h"

#include <iostream>
using namespace std;

namespace model
{
class InterlacedStudentList
{
    public:
        InterlacedStudentList();
        virtual ~InterlacedStudentList();
        void insert(StudentNode* node);
        void remove(const string& firstName, const string& lastName);
        void print();
    protected:

    private:
        StudentNode* root;
        void printList(StudentNode* node);
        void swapNodes(StudentNode* node1, StudentNode* node2);
        void addNameNode(StudentNode* node);

};
}


#endif // INTERLACEDSTUDENTLIST_H
