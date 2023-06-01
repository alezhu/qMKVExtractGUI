#include "Application.h"
#include <QApplication>
#include "MainWindow.h"

int Application::start(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("Alezhu");
	QCoreApplication::setApplicationName("qMKVExtractGUI");

	QApplication app(argc, argv);
	MainWindow w;
	w.show();
	return app.exec();
}
