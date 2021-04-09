#include "AddStudentWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{

//
// Constructs an add student window creating and initializing all the widgets that will be displayed
//
// @precondition none
// @postcondition none
//
AddStudentWindow::AddStudentWindow() : OKCancelWindow(330, 185, "Student to add")
{
    const int X_INPUT_LOCATION = 110;

    this->pStudent = 0;

    begin();

    this->firstNameInput = new Fl_Input(X_INPUT_LOCATION, 15, 200, 25, "First name:");
    this->lastNameInput = new Fl_Input(X_INPUT_LOCATION, 45, 200, 25, "Last name:");
    this->classificationInput = new Fl_Input(X_INPUT_LOCATION, 75, 200, 25, "Classification:");
    this->gradeInput = new Fl_Input(X_INPUT_LOCATION, 105, 60, 25, "Grade:");

    this->setOKLocation(90, 140);
    this->setCancelLocation(170, 140);

    end();
}

//
// The instance handler when OK is invoked
//
// @precondition none
// @postcondition getStudent() ==  object created from data user entered
//
void AddStudentWindow::okHandler()
{
    string firstName = this->firstNameInput->value();
    string lastName = this->lastNameInput->value();

    Student::Classification classification = this->determineAndSetClassificationBasedOnUserInput();

    try
    {
        int grade = this->determineAndSetGradeBasedOnUserInput();
        this->pStudent = new Student(firstName, lastName, classification, grade);
        this->hide();
    }
    catch (const char* message)
    {
        fl_message("%s", message);
    }

}

Student::Classification AddStudentWindow::determineAndSetClassificationBasedOnUserInput()
{
    string classificationStr = this->classificationInput->value();
    classificationStr = toUpperCase(classificationStr);

    Student::Classification classification = Student::Classification::UNKNOWN;

    if (classificationStr == Student::DualEnrollment)
    {
        classification = Student::Classification::DUALENROLLMENT;
    }
    else if (classificationStr == Student::Undergrad)
    {
        classification = Student::Classification::UNDERGRAD;
    }
    else if (classificationStr == Student::Grad)
    {
        classification = Student::Classification::GRAD;
    }
    else if (classificationStr == Student::Postdoc)
    {
        classification = Student::Classification::POSTDOC;
    }

    return classification;
}

int AddStudentWindow::determineAndSetGradeBasedOnUserInput()
{
    string gradeStr = this->gradeInput->value();

    istringstream streamConversion(gradeStr);
    int grade = 0;
    if (!(streamConversion >> grade))
    {
        throw "Error converting grade to an integer.";
    }

    return grade;
}

//
// The instance handler when cancel is invoked
//
// @precondition none
// @postcondition getStudent() == 0
//
void AddStudentWindow::cancelHandler()
{
    if (this->pStudent)
    {
        delete pStudent;
    }

    this->pStudent = 0;
    this->hide();
}

//
// Gets the student object created from the data the user entered.
//
// @precondition none
// @postcondition none
//
// @return The student object
//
Student* AddStudentWindow::getStudent() const
{
    return this->pStudent;
}

//
// Destructor that cleans up all allocated resources for the window
//
AddStudentWindow::~AddStudentWindow()
{
    delete this->firstNameInput;
    delete this->lastNameInput;
    delete this->classificationInput;
    delete this->gradeInput;
}

}
