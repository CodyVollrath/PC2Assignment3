#include "Student.h"

namespace model
{

// Define constants associated with Student class
const string Student::DualEnrollment = "DUALENROLLMENT";
const string Student::Undergrad = "UNDERGRAD";
const string Student::Grad = "GRAD";
const string Student::Postdoc = "POSTDOC";

//
// Constructs a student object
//
// @precondition none
// @postcondition none
//
// @param firstName first name of student
// @param lastName last name of student
// @param classification type of student - grad, undergrad, etc.
// @param grade grade student has earned
//
Student::Student(const string& firstName, const string& lastName, Classification classification, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->classification = classification;
    this->grade = grade;
}

//
// Gets the student's first name
//
// @precondition none
// @postcondition none
//
// @return Student's first name
//
const string& Student::getFirstName() const
{
    return this->firstName;
}

//
// Gets the student's last name
//
// @precondition none
// @postcondition none
//
// @return Student's last name
//
const string& Student::getLastName() const
{
    return this->lastName;
}

//
// Gets the student's classification
//
// @precondition none
// @postcondition none
//
// @return Student's classification
//
Student::Classification Student::getClassification() const
{
    return this->classification;
}

//
// Gets the student's grade earned
// @precondition none
// @postcondition none
//
// @return Student's grade earned
//
int Student::getGrade() const
{
    return this->grade;
}

//
// Destructor that cleans up all allocated resources for the Student object
//
Student::~Student()
{
    //dtor
}

}
