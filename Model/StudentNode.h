#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include "Student.h"

namespace model
{
class StudentNode
{
    public:
        StudentNode(Student* student);
        virtual ~StudentNode();

        StudentNode* getNextName() const;
        StudentNode* getNextClassification() const;
        StudentNode* getNextGrade() const;

        void setNextName(StudentNode* nextStudentNode);
        void setNextClassification(StudentNode* nextStudentNode);
        void setNextGrade(StudentNode* nextStudentNode);
        Student* getStudent() const;
        int compareLastName(StudentNode* other) const;
        int compareFirstName(StudentNode* other) const;
        int compareClassification(StudentNode* other) const;
        int compareGrade(StudentNode* other) const;
    protected:

    private:
        Student* currentStudent;
        StudentNode* nextNameStudentNode;
        StudentNode* nextClassificationStudentNode;
        StudentNode* nextGradeStudentNode;

};
}


#endif // STUDENTNODE_H
