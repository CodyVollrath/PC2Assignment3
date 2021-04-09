#ifndef CLASSROSTERWINDOW_H
#define CLASSROSTERWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <string>
using namespace std;

namespace view
{

//
// Defines the window where a user can load, save, add, and delete students from a class roster
//
class ClassRosterWindow : public Fl_Window
{
public:
    //
    // Defines the sorting methods that can be used to sort the class roster
    //
    enum SortOrder {NAME_ASCENDING, NAME_DESCENDING, CLASSIFICATION_ASCENDING, CLASSIFICATION_DESCENDING, GRADE_ASCENDING, GRADE_DESCENDING};

private:
    static const int SORTING_GROUPS = 3;
    static const int SORTING_TYPES_PER_GROUP = 2;
    static const int TOTAL_SORTING_METHODS = SORTING_GROUPS * SORTING_TYPES_PER_GROUP;

    vector<string> sortingGroup = {"Name", "Classif.", "Grade"};
    vector<string> sortingTypes = {"Ascending", "Descending"};
    string* radioSortingLabels[TOTAL_SORTING_METHODS];

    Fl_Output *sortingOutputLabel;
    Fl_Group *sortingRadioGroup;
    Fl_Round_Button *sortingRadioGroupButton[TOTAL_SORTING_METHODS];
    SortOrder sortOrderSelection;

    Fl_Output *classRosterSummaryOutputLabel;

    Fl_Text_Buffer *summaryOutputTextBuffer;
    Fl_Text_Display *summaryOutputTextDisplay;

    Fl_Button* loadButton;
    Fl_Button* saveButton;
    Fl_Button* addButton;
    Fl_Button* deleteButton;

    string selectedFilename;

    void createAndDisplaySortingRadioButtons();
    void setSortOrderBasedOnSelection();

    void draw();

public:
    ClassRosterWindow(int width, int height, const char* title);
    virtual ~ClassRosterWindow();

    static void cbSortingMethodChanged(Fl_Widget* widget, void* data);
    void sortingMethodChanged();

    static void cbLoad(Fl_Widget* widget, void* data);
    static void cbSave(Fl_Widget* widget, void* data);
    const string promptUserForFilename(int type, const string& title);
    const string getFilename() const;

    static void cbAddStudent(Fl_Widget* widget, void* data);
    static void cbDeleteStudent(Fl_Widget* widget, void* data);

    ClassRosterWindow::SortOrder getSortOrder() const;

    void setSummaryText(const string& outputText);
};

}

#endif // CLASSROSTERWINDOW_H
