#pragma once

#include <Model.h>
#include <QMainWindow>
#include <SettingsManager.h>
#include <QComboBox>
#include <QMetaEnum>
#include "ExtractionMode.h"

using qmkv::extract::chapter_types::ChapterTypes;
using qmkv::extract::extraction_mode::ExtractionMode;
using qmkv::model::Model;
using qmkv::model::SettingsManager;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
  explicit MainWindow(
    Model &model,
    SettingsManager &settingsManager,
    QWidget *parent = nullptr
  );

  ~MainWindow() override;

protected:
  virtual void changeEvent(QEvent *event) override;

  virtual void resizeEvent(QResizeEvent *event) override;

  virtual void moveEvent(QMoveEvent *event) override;


private:
  Ui::MainWindow *ui{};
  Model &m_model;
  SettingsManager &m_settingsManager;

  template<typename T>
  void _fillComboboxFromEnum(QComboBox *comboBox, T setCurrent)
  {
    auto metaEnum = QMetaEnum::fromType<T>();
    int index = -1;
    for(int i = 0; i < metaEnum.keyCount(); ++i) {
      if(metaEnum.value(i) == static_cast<int>(setCurrent)) {
        index = i;
        break;
      }
    }
    _fillComboboxFromMetaEnum(metaEnum, comboBox, index);
  };

  void _fillComboboxFromMetaEnum(const QMetaEnum &metaEnum, QComboBox *comboBox, int setCurrentIndex);

  void _restoreSizeAndPositionFromSettings();

  void _saveSizeAndPositionToSettings();

private slots:

  void btnBrowseMKVToolnixPath_clicked();

  void cmbChapterType_currentIndexChanged(int index);


  void model_MKVToolnixPath_changed(QAnyStringView value);

  void model_Extracting_changed(const bool value);

  void clearStatus();

  void model_StatusText_changed(QAnyStringView value);

  void model_StatusProgress_changed(uint value);

  void model_TotalStatusText_changed(QAnyStringView value);

  void model_TotalStatusProgress_changed(uint value);
};
