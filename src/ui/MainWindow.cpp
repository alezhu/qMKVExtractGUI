#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "Helper.h"
#include "SettingsManager.h"


MainWindow::~MainWindow() {
    delete ui;
}

MainWindow::MainWindow(qmkv::model::SettingsManager &settingsManager, qmkv::model::Model &model, QWidget *parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow),
          m_model{model},
          m_settingsManager{settingsManager} {
    ui->setupUi(this);

}