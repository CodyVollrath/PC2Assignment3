#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include "OKCancelWindow.h"
#include "Student.h"
using namespace model;

#include <Fl/Fl_Input.H>

namespace view
{

//
// Defines the window where the user can enter the first name, last name, classification and grade of a student
//
class AddStudentWindow : public OKCancelWindow
{
private:
    Fl_Input* firstNameInput;
    Fl_Input* lastNameInput;
    Fl_Input* classificationInput;
    Fl_Input* gradeInput;

    Student* pStudent;

    Student::Classification determineAndSetClassificationBasedOnUserInput();
    int determineAndSetGradeBasedOnUserInput();

public:
    AddStudentWindow();
    virtual ~AddStudentWindow();

    void okHandler();
    void cancelHandler();

    Student* getStudent() const;
};

}

#endif // ADDSTUDENTWINDOW_H
