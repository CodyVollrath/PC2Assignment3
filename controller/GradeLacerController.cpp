#include "GradeLacerController.h"

namespace controller
{
GradeLacerController::GradeLacerController()
{
    this->parser = new CSVParser();
}

GradeLacerController::~GradeLacerController()
{
    //dtor
}

string GradeLacerController::getFileData(const string& fileName) const
{
    FileLoader loader(fileName);
    string csvData = loader.loadFile();
    this->parser->getLinkedList(csvData);
    return "";
}
}

