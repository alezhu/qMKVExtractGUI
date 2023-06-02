#include "Application.h"
#include <Logger.h>
#include <QApplication>
#include <SettingsManager.h>
#include "MainWindow.h"

int Application::start(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("Alezhu");
    QCoreApplication::setApplicationName("qMKVExtractGUI");

    qmkv::extract::Logger logger;
    QApplication app(argc, argv);
    qmkv::model::SettingsManager sm{logger};
    qmkv::model::Model model{};

    MainWindow w{sm, model};
    w.show();
    return app.exec();
}
