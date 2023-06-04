#include <QMessageBox>
#include <QCoreApplication>
#include <QApplication>
#include "utils.h"

namespace qmkv::ui {
    void showErrorMessage(QAnyStringView msg, QWidget *parent) {
        auto title = QCoreApplication::translate(nullptr, "Error!");
        auto text = QCoreApplication::translate(nullptr, "An error has occured!")
                    + QString("\n\n")
                    + msg.toString();
        auto _parent = parent != nullptr ? parent : QApplication::activeWindow();
        QMessageBox::critical(_parent, title, text);
    }
}