#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class File {
private:
    string fileName;

    unsigned int fileLength;

public:
    File (string& fileName);

    File (string &fileName, unsigned int fileLength);

    ~File ();

    void setFileName (string fileName);

    char *getFileName ();

    void setFileLength (unsigned int fileLength);

    unsigned int getFileLength ();

    char *readFromFile ();

    void saveToFile (char *data);

    unsigned int countFileSize (ifstream &file);
};

#endif // FILE_PROCESSING_H
