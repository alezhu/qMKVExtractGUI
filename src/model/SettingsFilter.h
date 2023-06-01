#pragma once

#include <Logger.h>
#include <QObject>
#include <QSharedPointer>

namespace qmkv::model
{

  class SettingsFilter : public QObject
  {
    Q_OBJECT
  public:
    explicit SettingsFilter(QSharedPointer<qmkv::extract::Logger> logger, QObject *parent = nullptr);

    // QObject interface
  public:
    bool eventFilter(QObject *watched, QEvent *event) override;

    private:
    QSharedPointer<qmkv::extract::Logger> m_logger;
  };

}
