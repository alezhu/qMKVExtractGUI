#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "Helper.h"
#include "SettingsManager.h"

#include <Logger.h>

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);

}

MainWindow::~MainWindow()
{
        delete ui;
}

