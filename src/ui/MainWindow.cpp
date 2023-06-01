#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "Helper.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        qmkv::extract::Helper helper;
        QString title("0 1\"2:3#4\\5[6]");
        title += helper.EscapeString(title);
        setWindowTitle(title);
}

MainWindow::~MainWindow()
{
        delete ui;
}

