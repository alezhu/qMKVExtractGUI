#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QMessageBox>
#include <QFileDialog>


MainWindow::~MainWindow() {
    delete ui;
}

MainWindow::MainWindow(qmkv::model::SettingsManager &settingsManager, qmkv::model::Model &model, QWidget *parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow),
          m_model{model} {
    ui->setupUi(this);

    setWindowTitle(QString("qMKVExtractGUI v%1 -- by alezhu").arg(QCoreApplication::applicationVersion()));

    connect(&m_model, &qmkv::model::Model::MKVToolnixPathChanged, ui->txtMKVToolnixPath,
            [=](QStringView value) { ui->txtMKVToolnixPath->setText(value.toString()); });
}

void MainWindow::btnBrowseMKVToolnixPath_clicked() {
    auto path = m_model.MKVToolnixPath().toString();
    if (!path.isEmpty()) {
        if (QMessageBox::Yes !=
            QMessageBox::question(this, tr("Are you sure?"), tr("Do you really want to change MKVToolnix path?"))) {
            return;
        }
    }
    QFileDialog ofd(this, tr("Select MKVToolnix directory..."));
    if (QDir(path).exists()) {
        ofd.setDirectory(path);
    }
    ofd.setFileMode(QFileDialog::Directory);
    ofd.setOptions(QFileDialog::ShowDirsOnly);
    if (ofd.exec()) {
        auto files = ofd.selectedFiles();
        if (!files.isEmpty()) {
            m_model.setMKVToolnixPath(files.first());
        }
    }
}


MainWindow::MainWindow(qmkv::model::Model &model, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_model{model}
{
