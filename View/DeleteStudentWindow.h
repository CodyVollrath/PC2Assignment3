#ifndef DELETESTUDENTWINDOW_H
#define DELETESTUDENTWINDOW_H

#include "OKCancelWindow.h"

#include <Fl/Fl_Input.H>

#include <string>
using namespace std;

namespace view
{

//
// Defines the window where the user can enter the name of a student to delete
//
class DeleteStudentWindow : public OKCancelWindow
{
private:
    Fl_Input* firstNameInput;
    Fl_Input* lastNameInput;
    string firstName;
    string lastName;

public:
    DeleteStudentWindow();
    virtual ~DeleteStudentWindow();

    void okHandler();
    void cancelHandler();

    const string getFirstName() const;
    const string getLastName() const;
};

}

#endif // DELETESTUDENTWINDOW_H
