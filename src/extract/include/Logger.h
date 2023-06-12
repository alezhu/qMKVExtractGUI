#pragma once

#include <QDateTime>
#include <QObject>

namespace qmkv::extract {
  class Logger : public QObject {
  Q_OBJECT

  public:
    explicit Logger(QObject *parent = nullptr);

    QString LogText() const;

    static Logger *getInstance();

  public slots:

    void clear();

    void log(QStringView message);

  signals:

    void lineAdded(QStringView line, QDateTime dt);

  protected:
    QStringList m_log;
    static Logger *m_instance;
  };
} // namespace qmkv::extract
