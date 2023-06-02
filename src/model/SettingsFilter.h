#pragma once

#include <Logger.h>
#include <QObject>

namespace qmkv::model
{

  class SettingsFilter : public QObject
  {
    Q_OBJECT
  public:
    explicit SettingsFilter(qmkv::extract::Logger& logger, QObject *parent = nullptr);

    // QObject interface
  public:
    bool eventFilter(QObject *watched, QEvent *event) override;

    private:
    qmkv::extract::Logger& m_logger;
  };

}
