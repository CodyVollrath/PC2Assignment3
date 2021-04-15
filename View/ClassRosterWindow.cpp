#include "ClassRosterWindow.h"

#include "DeleteStudentWindow.h"
#include "AddStudentWindow.h"

#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <Fl/Fl_File_Chooser.H>

#define DIAGNOSTIC_OUTPUT


#ifdef DIAGNOSTIC_OUTPUT
#include <iostream>
#endif

namespace view
{

//
// Constructs a class roster window creating and initializing all the widgets that will be displayed
//
// @precondition width > 0 AND height > 0
// @postcondition none
//
// @param width The width of the window
// @param height The height of the window
// @param title The title to display for the window
//
ClassRosterWindow::ClassRosterWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->controllerInstance = new GradeLacerController();
    this->sortingOutputLabel = new Fl_Output(120, 25, 0, 0, "Sorting order:");
    createAndDisplaySortingRadioButtons();

    this->classRosterSummaryOutputLabel = new Fl_Output(190, 110, 0, 0, "Class roster summary:");

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(20, 120, 500, 200);
    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);

    this->loadButton = new Fl_Button(120, 330, 70, 30, "Load");
    this->loadButton->callback(cbLoad, this);

    this->saveButton = new Fl_Button(200, 330, 70, 30, "Save");
    this->saveButton->callback(cbSave, this);

    this->addButton = new Fl_Button(280, 330, 70, 30, "Add");
    this->addButton->callback(cbAddStudent, this);

    this->deleteButton = new Fl_Button(360, 330, 70, 30, "Delete");
    this->deleteButton->callback(cbDeleteStudent, this);

    this->setSummaryText("Demo of how to set the summary text.");

    end();
}

//
// Overriding drawing of FL_Window so can draw a box around the sorting type radio buttons
// to make them appear in a group
//
void ClassRosterWindow::draw()
{
    Fl_Window::draw();
    fl_frame("AAAA", 20, 35, 500, 55);
}


void ClassRosterWindow::createAndDisplaySortingRadioButtons()
{
    const int X_RADIO_GROUP = 35;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->sortingRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->sortingRadioGroup->begin();

    for (int i=0; i<SORTING_GROUPS; i++)
    {
        for (int j = 0; j<SORTING_TYPES_PER_GROUP; j++)
        {
            string label = this->sortingGroup[i] + " " + this->sortingTypes[j];
            int offset = (i*SORTING_TYPES_PER_GROUP) + j;
            this->radioSortingLabels[offset] = new string(label);
            this->sortingRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, radioSortingLabels[offset]->c_str());
            this->sortingRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->sortingRadioGroupButton[offset]->callback(cbSortingMethodChanged, this);
        }
    }

    this->sortingRadioGroup->end();

    this->sortingRadioGroupButton[0]->set();
    this->sortOrderSelection = NAME_ASCENDING;
}

//
// Callback when a radio button for the way to sort the students has changed
//
// @precondition widget != 0 AND data != 0
// @postcondition ClassRosterWindow::getSortOrder() == value of new sort order selected
//
// @param widget The widget that initiated the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void ClassRosterWindow::cbSortingMethodChanged(Fl_Widget* widget, void* data)
{
    ClassRosterWindow* window = (ClassRosterWindow*)data;
    window->sortingMethodChanged();
    window->displaySortedList();
#ifdef DIAGNOSTIC_OUTPUT
    cout << "Sorting method: " << window->getSortOrder() << endl;
#endif
}

//
// Callback that is an instance function of the window class to encapsulate function
//
// @precondition none
// @postcondition getSortOrder() == value of new sort order selected
//
void ClassRosterWindow::sortingMethodChanged()
{
    this->setSortOrderBasedOnSelection();
}

//
// Callback when the Load button is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition ClassRosterWindow::getFilename() == file selected by the user
//
// @param widget The widget that initiatied the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void ClassRosterWindow::cbLoad(Fl_Widget* widget, void* data)
{
    ClassRosterWindow* window = (ClassRosterWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::SINGLE, "Class roster file to load");
    window->loadFileData();
    window->displaySortedList();
#ifdef DIAGNOSTIC_OUTPUT
    cout << "Filename selected: " << window->getFilename() << endl;
#endif

}

//
// Callback when the Load button is invoked
//
// @precondition type == Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
// @postcondition ClassRosterWindow::getFilename() == file selected by the user
//
// @param type Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
// @param title Title to display for the file chooser
//
// @return The filename the user selected
//
const string ClassRosterWindow::promptUserForFilename(int type, const string& title)
{
    Fl_File_Chooser chooser(".", "*", type, title.c_str());
    chooser.show();

    while(chooser.shown())
    {
        Fl::wait();
    }

    if (chooser.value() != 0)
    {
        this->selectedFilename = chooser.value();
    }
    else
    {
        this->selectedFilename = "";
    }

    return this->selectedFilename;
}

//
// Gets the filename the user selected when the file chooser was invoked
//
// @precondition none
// @postcondition none
//
// @return The filename the user had selected when the file chooser was invoked
//
const string ClassRosterWindow::getFilename() const
{
    return this->selectedFilename;
}

//
// Callback when the Save button is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition ClassRosterWindow::getFilename() == file selected by the user
//
// @param widget The widget that initiated the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void ClassRosterWindow::cbSave(Fl_Widget* widget, void* data)
{
    ClassRosterWindow* window = (ClassRosterWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::CREATE, "Class roster file to save to");
    string dataToSave = window->summaryOutputTextBuffer->text();
    window->controllerInstance->writeDataToOutfile(window->getFilename(), dataToSave);
#ifdef DIAGNOSTIC_OUTPUT
    cout << "Filename selected: " << window->getFilename() << endl;
#endif

}

//
// Callback when the Add button is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition none
//
// @param widget The widget that initiated the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void ClassRosterWindow::cbAddStudent(Fl_Widget* widget, void* data)
{
    ClassRosterWindow* window = (ClassRosterWindow*)data; // TODO Currently, not used by may need to be used when adapt code

    AddStudentWindow addStudent;
    addStudent.set_modal();
    addStudent.show();

    while (addStudent.shown())
    {
        Fl::wait();
    }

    if (addStudent.getWindowResult() == OKCancelWindow::WindowResult::OK){
        window->controllerInstance->addStudent(addStudent.getStudent());
    }
    window->displaySortedList();

#ifdef DIAGNOSTIC_OUTPUT
    // TODO Remove or adapt code below, currently in for demo purposes
    if (addStudent.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        Student* pStudent = addStudent.getStudent();
        cout << "OK" << endl;
        cout << "First name: " << pStudent->getFirstName() << endl;
        cout << "Last name: " << pStudent->getLastName() << endl;
        cout << "Classification: " << pStudent->getClassification() << endl;
        cout << "Grade: " << pStudent->getGrade() << endl;
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
#endif

}

//
// Callback when the Delete button is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition none
//
// @param widget The widget that initiated the callback
// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
//
void ClassRosterWindow::cbDeleteStudent(Fl_Widget* widget, void* data)
{
    ClassRosterWindow* window = (ClassRosterWindow*)data;

    DeleteStudentWindow deleteStudent;
    deleteStudent.set_modal();
    deleteStudent.show();

    while (deleteStudent.shown())
    {
        Fl::wait();
    }

    if (deleteStudent.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        window->controllerInstance->removeStudent(deleteStudent.getFirstName(), deleteStudent.getLastName());
    }
    window->displaySortedList();

#ifdef DIAGNOSTIC_OUTPUT
    if (deleteStudent.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        cout << "OK - Student name: " << deleteStudent.getFirstName() << " " << deleteStudent.getLastName() << endl;
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
#endif

}

//
// Determines and sets the sort order based on the radio button the user has selected.
//
// @preconditon none
// @postcondition getSortOrder() == sort order that user selected
//
void ClassRosterWindow::setSortOrderBasedOnSelection()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->sortingRadioGroupButton[i]->value())
        {
            this->sortOrderSelection = (SortOrder)i;
        }
    }
}

void ClassRosterWindow::loadFileData()
{
    this->controllerInstance->createStudentCollection(this->getFilename());
}

void ClassRosterWindow::displaySortedList()
{
    cout << this->controllerInstance->getReport(this->getSortOrder()) << endl;
    this->setSummaryText(this->controllerInstance->getReport(this->getSortOrder()));
}
//
// Sets the summary test to display in the class roster summary output
//
// @precondition none
// @postcondition none
//
// @param outputText The text to display
//
void ClassRosterWindow::setSummaryText(const string& outputText)
{
    this->summaryOutputTextBuffer->text(outputText.c_str());
}

//
// Gets the sort order the user has selected
//
// @precondition none
// @postcondition none
//
// @return The sort order the user has selected
//
ClassRosterWindow::SortOrder ClassRosterWindow::getSortOrder() const {
    return this->sortOrderSelection;
}

//
// Destructor that cleans up all allocated resources for the window
//
ClassRosterWindow::~ClassRosterWindow()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        delete this->radioSortingLabels[i];
        delete this->sortingRadioGroupButton[i];
    }

    delete this->sortingOutputLabel;

    delete this->classRosterSummaryOutputLabel;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;

    delete this->loadButton;
    delete this->saveButton;
    delete this->addButton;
    delete this->controllerInstance;
    delete this->deleteButton;
}

}

