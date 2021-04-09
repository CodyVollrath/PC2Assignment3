#include "DeleteStudentWindow.h"

#include <iostream>
using namespace std;

namespace view
{

//
// Constructs a delete student window creating and initializing all the widgets that will be displayed
//
// @precondition none
// @postcondition none
//
DeleteStudentWindow::DeleteStudentWindow() : OKCancelWindow(330, 120, "Student to delete")
{
    begin();

    this->firstNameInput = new Fl_Input(110, 15, 200, 25, "First name:");
    this->lastNameInput = new Fl_Input(110, 45, 200, 25, "Last name:");
    this->setOKLocation(90, 80);
    this->setCancelLocation(170, 80);

    end();
}

//
// The instance handler when OK is invoked
//
// @precondition none
// @postcondition getFirstName() == first name user entered && getLastName() == last name user entered
//
void DeleteStudentWindow::okHandler()
{
    this->firstName = this->firstNameInput->value();
    this->lastName = this->lastNameInput->value();
    this->hide();
}

//
// The instance handler when Cancel is invoked
//
// @precondition none
// @postcondition getFirstName() == "" AND getLastName() == ""
//
void DeleteStudentWindow::cancelHandler()
{
    this->firstName = "";
    this->lastName = "";
    this->hide();
}

//
// Gets the student's first name entered
//
// @precondition none
// @postcondition none
//
// @return The first name entered
//
const string DeleteStudentWindow::getFirstName() const
{
    return this->firstName;
}


//
// Gets the student's last name entered
//
// @precondition none
// @postcondition none
//
// @return The last name entered
//
const string DeleteStudentWindow::getLastName() const
{
    return this->lastName;
}

//
// Destructor that cleans up all allocated resources for the window
//
DeleteStudentWindow::~DeleteStudentWindow()
{
    delete this->firstNameInput;
    delete this->lastNameInput;
}

}

