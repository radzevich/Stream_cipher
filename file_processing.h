#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

#include <QString>
#include <iostream>
#include <fstream>
#include

using namespace std;

namespace File_processing {

    QString getFileName ();

    char *readFromFile (QString &fileName);

    void saveToFile (char *data);

    unsigned int getFileSize (string fileName);
}

#endif // FILE_PROCESSING_H
