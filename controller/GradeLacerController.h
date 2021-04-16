#ifndef GRADELACERCONTROLLER_H
#define GRADELACERCONTROLLER_H
#include "Utils.h"
#include <string>
using namespace std;

#include "FileLoader.h"
#include "FileSaver.h"
using namespace datatier;

#include "CSVParser.h"
using namespace model;


namespace controller
{
/**
* The GradeLacerController class performs the operations on the model that relays back to the view
* @author CodyVollrath
*/
class GradeLacerController
{
    public:
        /**
        * Creates an instance of the GradeLaceController
        */
        GradeLacerController();

        /**
        * Deconstructs the gradeLacerController and frees memory
        */
        virtual ~GradeLacerController();

        /**
        * Creates a student collection in the form of an interlaced list from a file
        * @param fileName the name of the file to read from
        */
        void createStudentCollection(const string& fileName);

        /**
        * Get's a report on the data collected from the list
        * @param selectionNumber the selection value entered for how the data is arranged
        * @return the report in a string format
        */
        string getReport(int selectionNumber) const;

        /**
        * Add's an individual student from the list
        * @param student the student to be added
        */
        void addStudent(Student* student);

        /**
        * Removes a student from the list by first and last name
        * @param firstName the first name of the student
        * @param lastName the last name of the student
        */
        void removeStudent(const string& firstName, const string& lastName);

        /**
        * Writes data to an output file
        * @param outfile the output file name
        * @param data the data to be written to that file
        */
        void writeDataToOutfile(const string& outfile, const string& data);
    protected:

    private:
        CSVParser* parser;
        InterlacedStudentList* students;
        void generateReport();
};
}


#endif // GRADELACERCONTROLLER_H
