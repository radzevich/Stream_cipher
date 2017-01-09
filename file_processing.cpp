#include "file_processing.h"


//File open dialog, getting chosed file name.
QString File_processing :: getFileName ()
{
    QString filename = QFileDialog :: getOpenFileName (
                this,
                tr ("Open file"),
                "/home/virtuain",
                "All files (*.*);; Pictures (*.jpeg, *.png, *.bmp);; Music (*.mp3);; Video (*.mp4)"
                );
    return filename;
}


//Reading data from file.
char *File_processing :: readFromFile (QString &fileName)
{
    ifstream fin (getFileName().toStdString());

    if (!fin.is_open())
        return NULL;
    else
    {
        unsigned int fileSize = getFileSize(fin);

        char * buff = calloc (fileSize, 1);

        for (unsigned int i = 0; i < fileSize; i++)
            fin >> buff [i];
    }

    return buff;
}


//Saving data to file.
void File_processing :: saveToFile (char *data)
{

}


//Getting file size.
unsigned int File_processing :: getFileSize (FILE file)
{
    file.seekg (0, std :: ios :: end);
    size = file.tellg();
    return size;
}
