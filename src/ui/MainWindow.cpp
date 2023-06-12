#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "ExtractionMode.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::~MainWindow()
{
  delete ui;
}

MainWindow::MainWindow(
  Model &model,
  SettingsManager &settingsManager,
  QWidget *parent
) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_model{model},
  m_settingsManager{settingsManager}
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

  // Set form size and position from settings
  _restoreSizeAndPositionFromSettings();
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

constexpr QAnyStringView settings_MainWindow_geometry{"MainWindow/geometry"};
constexpr QAnyStringView settings_MainWindow_state{"MainWindow/state"};

void MainWindow::_restoreSizeAndPositionFromSettings()
{
  auto logger = &m_model.logger();
  logger->log(tr("Begin setting form size and position from settings..."));
  QSettings settings(this);
  restoreGeometry(settings.value(settings_MainWindow_geometry).toByteArray());
  restoreState(settings.value(settings_MainWindow_state).toByteArray());

  logger->log(tr("Finished setting form size and position from settings!"));
}

void MainWindow::_saveSizeAndPositionToSettings()
{
  auto logger = &m_model.logger();
  QSettings settings(this);
  settings.setValue(settings_MainWindow_geometry, saveGeometry());
  settings.setValue(settings_MainWindow_state, saveState());

  logger->log(tr("Changing size and position"));
}

void MainWindow::changeEvent(QEvent *event)
{
  switch(event->type()) {
    case QEvent::WindowStateChange:
      _saveSizeAndPositionToSettings();
      break;
  }
  QWidget::changeEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
  _saveSizeAndPositionToSettings();
  QWidget::resizeEvent(event);
}

void MainWindow::moveEvent(QMoveEvent *event)
{
  _saveSizeAndPositionToSettings();
  QWidget::moveEvent(event);
}




