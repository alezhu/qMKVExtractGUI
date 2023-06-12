#pragma once

#include <Model.h>
#include <QMainWindow>
#include <SettingsManager.h>
#include <QComboBox>
#include <QMetaEnum>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
  MainWindow(
    qmkv::model::Model &model, QWidget *parent = nullptr
  );

    ~MainWindow() override;

private:
  Ui::MainWindow *ui{};
  qmkv::model::Model &m_model;

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



    void btnBrowseMKVToolnixPath_clicked();
};
