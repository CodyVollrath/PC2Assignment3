#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include "Student.h"

namespace model
{
/**
* The StudentNode class contains a student
* @author CodyVollrath
*/
class StudentNode
{
    public:
        /**
        * Constructs a StudentNode object
        * @param student the student to be contained in the node
        */
        StudentNode(Student* student);

        /**
        * Deconstructs the StudentNode object
        */
        virtual ~StudentNode();

        /**
        * Gets the next student node for the name lace
        * @return the next student node in the name lace
        */
        StudentNode* getNextName() const;

        /**
        * Gets the next student node for the classification lace
        * @return the next student node in the classification lace
        */
        StudentNode* getNextClassification() const;

        /**
        * Gets the next student node for the grade lace
        * @return the next student node in the grade lace
        */
        StudentNode* getNextGrade() const;

        /**
        * Sets the next name lace to the entered student node
        * @param nextStudentNode the studentNode to be entered
        * @pre none
        * @post getNextName() == nextStudentNode
        */
        void setNextName(StudentNode* nextStudentNode);

        /**
        * Sets the next classification lace to the entered student node
        * @param nextStudentNode the studentNode to be entered
        * @pre none
        * @post getNextClassification() == nextStudentNode
        */
        void setNextClassification(StudentNode* nextStudentNode);

        /**
        * Sets the next grade lace to the entered student node
        * @param nextStudentNode the studentNode to be entered
        * @pre none
        * @post getNextGrade() == nextStudentNode
        */
        void setNextGrade(StudentNode* nextStudentNode);

        /**
        * Gets the student inside the current node
        * @return the student inside the node
        */
        Student* getStudent() const;

        /**
        * Compares the lastname to the lastname of the other student
        * @return 0 if equal, -1 if other is greater, 1 if other is less, -2 if other is null
        */
        int compareLastName(StudentNode* other) const;

        /**
        * Compares the classification to the classification of the other student
        * @return 0 if equal, -1 if other is greater, 1 if other is less, -2 if other is null
        */
        int compareClassification(StudentNode* other) const;
    protected:

    private:
        Student* currentStudent;
        StudentNode* nextNameStudentNode;
        StudentNode* nextClassificationStudentNode;
        StudentNode* nextGradeStudentNode;

};
}


#endif // STUDENTNODE_H
