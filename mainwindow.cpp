#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QLabel"
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

void MainWindow::on_choose_file_triggered()
{

}
