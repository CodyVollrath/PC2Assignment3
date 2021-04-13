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
        string generateReport(int selectionNumber) const;
    protected:

    private:
        StudentNode* nameHead;
        StudentNode* classificationHead;
        StudentNode* gradeHead;
        string parseByName(StudentNode* node) const;

        void addNameNode(StudentNode* node);
        void addClassificationNode(StudentNode* node);
        void addGradeNode(StudentNode* node);

        string getReportByLastName(StudentNode* node) const;
        string getReportByLastNameDesc(StudentNode* node) const;

        string getReportByGrade(StudentNode* node) const;
        string getReportByGradeDesc(StudentNode* node) const;

        string getReportByClassification(StudentNode* node) const;
        string getReportByClassificationDesc(StudentNode* node) const;

};
}


#endif // INTERLACEDSTUDENTLIST_H
