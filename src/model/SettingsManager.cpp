#include "SettingsManager.h"
#include "SettingsManager_p.h"

namespace qmkv::model {

  SettingsManager::SettingsManager(extract::Logger &logger, QObject *parent) :
    QObject{parent},
    d_ptr(new SettingsManagerPrivate(logger, this))
  {
  }

  Settings *SettingsManager::get()
  {
    Q_D(SettingsManager);
    return d->get();
  }
}
