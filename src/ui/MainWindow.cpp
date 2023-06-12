#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "ExtractionMode.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::~MainWindow()
{
  delete ui;
}

MainWindow::MainWindow(Model &model, QWidget *parent)
  :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_model{model}
{
  ui->setupUi(this);

  setWindowTitle(QString("qMKVExtractGUI v%1 -- by alezhu").arg(QCoreApplication::applicationVersion()));

  model_MKVToolnixPath_changed(m_model.MKVToolnixPath());
  connect(&m_model, &Model::MKVToolnixPathChanged, this, &MainWindow::model_MKVToolnixPath_changed);

  model_Extracting_changed(false);
  connect(&m_model, &Model::ExtractingChanged, this, &MainWindow::model_Extracting_changed);

  _fillComboboxFromEnum<ChapterTypes>(ui->cmbChapterType, m_model.ChapterType());

  _fillComboboxFromEnum<ExtractionMode>(ui->cmbExtractionMode, ExtractionMode::Tracks);

  model_StatusText_changed(m_model.StatusText());
  connect(&m_model, &Model::StatusTextChanged, this, &MainWindow::model_StatusText_changed);

  model_TotalStatusText_changed(m_model.TotalStatusText());
  connect(&m_model, &Model::TotalStatusTextChanged, this, &MainWindow::model_TotalStatusText_changed);

  model_StatusProgress_changed(m_model.StatusProgress());
  connect(&m_model, &Model::StatusProgressChanged, this, &MainWindow::model_StatusProgress_changed);

  model_TotalStatusProgress_changed(m_model.TotalStatusProgress());
  connect(&m_model, &Model::TotalStatusProgressChanged, this, &MainWindow::model_TotalStatusProgress_changed);
  
  clearStatus();
}

void MainWindow::model_MKVToolnixPath_changed(QAnyStringView value)
{
  ui->txtMKVToolnixPath->setText(value.toString());
}

void MainWindow::model_Extracting_changed(const bool value)
{
  ui->btnAbort->setEnabled(value);
  ui->btnAbortAll->setEnabled(value);
  ui->btnOptions->setEnabled(!value);
}


void MainWindow::btnBrowseMKVToolnixPath_clicked()
{
  auto path = m_model.MKVToolnixPath().toString();
  if(!path.isEmpty()) {
    if(QMessageBox::Yes != QMessageBox::question(this, tr("Are you sure?"), tr("Do you really want to change MKVToolnix path?"))) {
      return;
    }
  }
  QFileDialog ofd(this, tr("Select MKVToolnix directory..."));
  if(QDir(path).exists()) {
    ofd.setDirectory(path);
  }
  ofd.setFileMode(QFileDialog::Directory);
  ofd.setOptions(QFileDialog::ShowDirsOnly);
  if(ofd.exec()) {
    auto files = ofd.selectedFiles();
    if(!files.isEmpty()) {
      m_model.setMKVToolnixPath(QStringView(files.first()));
    }
  }
}

void MainWindow::_fillComboboxFromMetaEnum(const QMetaEnum &metaEnum, QComboBox *comboBox, int setCurrentIndex = -1)
{
  comboBox->clear();
  for(int i = 0; i < metaEnum.keyCount(); ++i) {
    comboBox->addItem(metaEnum.key(i), metaEnum.value(i));
  }
  comboBox->setCurrentIndex(setCurrentIndex);
}

void MainWindow::cmbChapterType_currentIndexChanged(int index)
{
  auto metaEnum = QMetaEnum::fromType<qmkv::extract::chapter_types::ChapterTypes>();
  auto value = metaEnum.value(index);
  m_model.setChapterType(static_cast<qmkv::extract::chapter_types::ChapterTypes>(value));
}

void MainWindow::clearStatus()
{
  m_model.clearStatus();
}

void MainWindow::model_StatusText_changed(QAnyStringView value)
{
  ui->lblStatus->setText(value.toString());
}

void MainWindow::model_TotalStatusText_changed(QAnyStringView value)
{
  ui->lblTotalStatus->setText(value.toString());
}

void MainWindow::model_StatusProgress_changed(uint value)
{
  ui->prgBrStatus->setValue(static_cast<int>(value));
  ui->prgBrStatus->setVisible(value != 0);

}

void MainWindow::model_TotalStatusProgress_changed(uint value)
{
  ui->prgBrTotalStatus->setValue(static_cast<int>(value));
  ui->prgBrTotalStatus->setVisible(value != 0);
}



