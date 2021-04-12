#ifndef GRADELACERCONTROLLER_H
#define GRADELACERCONTROLLER_H

#include <string>
using namespace std;

#include "FileLoader.h"
using namespace datatier;

#include "CSVParser.h"
using namespace model;

namespace controller
{
class GradeLacerController
{
    public:
        GradeLacerController();
        virtual ~GradeLacerController();
        void createStudentCollection(const string& fileName);
    protected:

    private:
        CSVParser* parser;
        InterlacedStudentList* students;
};
}


#endif // GRADELACERCONTROLLER_H
