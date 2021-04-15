#include "FileSaver.h"
namespace datatier
{
FileSaver::FileSaver(const string& file)
{
    this->outfile = file;
}

FileSaver::~FileSaver()
{
    //dtor
}

void FileSaver::write(const string& data)
{
    ofstream file(this->outfile);
    file << data;
    file.close();
}
}

