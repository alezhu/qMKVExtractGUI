#include "Application.h"
#include <Logger.h>
#include <QApplication>
#include <SettingsManager.h>
#include "MainWindow.h"
#include "utils.h"

int Application::start(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("Alezhu");
    QCoreApplication::setApplicationName("qMKVExtractGUI");

    qmkv::extract::Logger logger;
    qmkv::extract::Helper helper;
    QApplication app(argc, argv);
    qmkv::model::SettingsManager sm{logger};
    qmkv::extract::ExtractFactory extractFactory;
    qmkv::model::Model model{&logger, &helper, &sm, &qmkv::ui::showErrorMessage, extractFactory};

    MainWindow w{sm, model};
    w.show();
    return app.exec();
}
