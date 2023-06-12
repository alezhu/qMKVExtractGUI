#include "SettingsFilter.h"
#include <QEvent>

namespace qmkv::model {

  bool SettingsFilter::eventFilter(QObject *watched, QEvent *event)
  {
    if(event->type() == QEvent::UpdateRequest && nullptr != &m_logger) {
      m_logger.log(tr("Saving settings..."));
    };
    return false;
  }

  qmkv::model::SettingsFilter::SettingsFilter(
    extract::Logger &logger, QObject *parent
  ) :
    QObject(parent),
    m_logger(logger)
  {
  }

} // namespace qmkv::model
