#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 实现窗口的生成与各种属性的设置、信号与槽的关联
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

