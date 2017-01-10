#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtGui>
#include <string>
#include "file_processing.h"

using namespace std;

char *data;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void process (QString fileName)
{
    string file = fileName.toStdString();

    File * inputFile = new File (file);

    data = inputFile->readFromFile();

    inputFile->~File();
}


void save (QString fileName)
{
    string file = fileName.toStdString();

    File * outputFile = new File (file, strlen(data));

    outputFile->saveToFile(data);

    outputFile->~File();

    free (data);
    data = NULL;
}

//File open dialog, getting name of selected file.
void MainWindow::on_pushButton_clicked()
{
    this->currentFileName = QFileDialog :: getOpenFileName (
                this,
                tr ("Open file"),
                "/home/virtuain",
                "All files (*.*);; Pictures (*.jpeg, *.png, *.bmp);; Music (*.mp3);; Video (*.mp4)"
                );
    process (this->currentFileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->currentFileName = QFileDialog :: getSaveFileName(
                this,
                tr ("Save file"),
                QDir :: currentPath(),
                tr("All files (*.*"));
    save (this->currentFileName);
}

