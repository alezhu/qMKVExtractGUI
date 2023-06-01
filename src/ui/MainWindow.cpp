#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "Helper.h"
#include "SettingsManager.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        qmkv::extract::Helper helper;
        QString title("0 1\"2:3#4\\5[6]");
        title += helper.EscapeString(title);
        setWindowTitle(title);
        QSharedPointer<qmkv::extract::Logger> logger;
        qmkv::model::SettingsManager sm{logger,this};
        auto sett = sm.get();
        sett->setShowPopup(true);
}

MainWindow::~MainWindow()
{
        delete ui;
}

