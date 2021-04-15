#ifndef INTERLACEDSTUDENTLIST_H
#define INTERLACEDSTUDENTLIST_H
#include "Student.h"
#include "StudentNode.h"
#include "Utils.h"

#include <iostream>
#include <vector>
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
        void removeNameNode(StudentNode** head_ref, const string& firstName, const string& lastName);
        void removeClassificationNode(StudentNode** head_ref,const string& firstName, const string& lastName);
        void removeGradeNode(StudentNode** head_ref,const string& firstName, const string& lastName);

        string getReportByLastName(StudentNode* node) const;
        string getReportByLastNameDesc(StudentNode* node) const;

        string getReportByGrade(StudentNode* node) const;
        string getReportByGradeDesc(StudentNode* node) const;

        string getReportByClassification(StudentNode* node) const;
        string getReportByClassificationDesc(StudentNode* node) const;
};
}


#endif // INTERLACEDSTUDENTLIST_H
