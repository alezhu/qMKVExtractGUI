#include "Logger.h"

namespace qmkv::extract {
  Logger::Logger(QObject *parent) : QObject{parent}
  {
  }

  constexpr QLatin1StringView emptyString("");

  QString Logger::LogText() const
  {
    return m_log.join(emptyString);
  }

  void Logger::clear()
  {
    m_log.clear();
  }

  void Logger::log(QStringView message)
  {
    auto now = QDateTime::currentDateTime();
    auto nowStr = now.toString("[yyyy-MM-dd][HH:mm:ss]");
    nowStr.reserve(message.length() + 1);
    auto logMessage = nowStr.append(" ").append(message);
    m_log.append(logMessage);
    emit lineAdded(QStringView(logMessage), now);
  }

}
