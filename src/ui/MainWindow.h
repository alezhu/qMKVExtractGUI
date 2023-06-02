#pragma once

#include <Model.h>
#include <QMainWindow>
#include <SettingsManager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(
            qmkv::model::SettingsManager &settingsManager,
            qmkv::model::Model &model,
            QWidget *parent = nullptr
    );

    ~MainWindow() override;

private:
    Ui::MainWindow *ui{};
    qmkv::model::SettingsManager &m_settingsManager;
    qmkv::model::Model &m_model;

public slots:

    void btnBrowseMKVToolnixPath_clicked();
};
