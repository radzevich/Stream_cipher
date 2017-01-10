#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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

//File open dialog, getting name of selected file.
void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog :: getOpenFileName (
                this,
                tr ("Open file"),
                "/home/virtuain",
                "All files (*.*);; Pictures (*.jpeg, *.png, *.bmp);; Music (*.mp3);; Video (*.mp4)"
                );

}
