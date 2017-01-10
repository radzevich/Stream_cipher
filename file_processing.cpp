#include "file_processing.h"


File :: File (string &fileName)
{
    this->fileName = fileName;

    ifstream fin (&(this->fileName[0]), ios_base :: in);

    this->fileLength = countFileSize (fin);

    fin.close();
}

File :: File (string &fileName, unsigned int fileLength)
{
    this->fileName = fileName;
    this->fileLength = fileLength;
}


File :: ~File ()
{
    fileName.~basic_string();
    free (this);
}


char *File :: getFileName ()
{
    return &(this->fileName[0]);
}


//Reading data from file.
char *File :: readFromFile ()
{
    ifstream fin (&(this->fileName[0]), ios_base :: in);

    if (!fin.is_open())
        return NULL;
    else
    {
        char * buff = (char *)calloc (fileLength, 1);

        for (unsigned int i = 0; i < fileLength; i++)
            fin >> buff [i];

        fin.close();

        return buff;
    }
}


//Saving data to file.
void File :: saveToFile (char *data)
{
    ofstream fout (&(this->fileName[0]));

    for (unsigned int i = 0; i < fileLength; i++)
        fout << data [i];

    fout.close();
}


//Getting file size.
unsigned int File :: countFileSize (ifstream &file)
{
    file.seekg (0, std :: ios :: end);
    return file.tellg();
}




