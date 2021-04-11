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
        void createStudentCollection(const string& fileName) const;

    protected:

    private:
        CSVParser* parser;
        vector<Student>* students;
};
}


#endif // GRADELACERCONTROLLER_H
