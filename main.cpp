
#include "ClassRosterWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    ClassRosterWindow mainWindow(540, 375, "Cody Vollrath's Class Roster");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
