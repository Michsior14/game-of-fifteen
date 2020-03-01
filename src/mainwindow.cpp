#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    size_t n = 4;

    size_t counter = 0;
    for (size_t i = 0; i< n; i++) {
        for (size_t j = 0; j<n; j++) {
            ui->playable_area->addWidget(new QPushButton(QString::number(++counter)), i, j);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

