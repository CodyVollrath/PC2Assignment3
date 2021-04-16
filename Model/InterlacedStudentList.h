#ifndef INTERLACEDSTUDENTLIST_H
#define INTERLACEDSTUDENTLIST_H
#include "Student.h"
#include "StudentNode.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

namespace model
{
/**
* InterlacedStudentList keeps track of the students using a laced approach with three laces
*   name, classification, and grade;
* @author CodyVollrath
*/
class InterlacedStudentList
{
    public:
        /**
        * Constructs the InterlacedStudentList
        */
        InterlacedStudentList();

        /**
        * Deconstructs the InterlacedStudentList
        */
        virtual ~InterlacedStudentList();

        /**
        * Inserts into the InterlacedStudentList
        * @param node the StudentNode to be inserted into the list
        */
        void insert(StudentNode* node);

        /**
        * Removes from the list by the first and last name
        * @param firstName the first name of the student
        * @param lastName the last name of the student
        */
        void remove(const string& firstName, const string& lastName);

        /**
        * Gets a report on the list data by the selection sort
        * @param selectionNumber the selection value which represents the sorted data
        * @return the report on the list
        */
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

        string formatItem(Student* student) const;
};
}


#endif // INTERLACEDSTUDENTLIST_H
