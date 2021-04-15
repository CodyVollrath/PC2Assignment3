#ifndef FILESAVER_H
#define FILESAVER_H

#include <fstream>
#include <string>
using namespace std;

namespace datatier
{
class FileSaver
{
    public:
        FileSaver(const string& file);
        virtual ~FileSaver();
        void write(const string& data);

    protected:

    private:
        string outfile;
};
}


#endif // FILESAVER_H
