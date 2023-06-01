#pragma once
#include "Settings.h"
#include <Logger.h>
#include <QSettings>
#include <QSharedPointer>

namespace qmkv::model
{

  class SettingsManagerPrivate;
  class SettingsManager : public QObject
  {
    Q_OBJECT
  public:
    explicit SettingsManager(QSharedPointer<extract::Logger> logger, QObject *parent = nullptr);

    Settings *get();

  private:
    QSharedPointer<SettingsManagerPrivate> d_ptr;
    Q_DECLARE_PRIVATE(SettingsManager);
  };
}
