#pragma once

#include <QObject>
#include "common.h"
#include "SettingsManager.h"
#include "Helper.h"
#include "ExtractFactory.h"

namespace qmkv::model {
  class Model : public QObject {
  Q_OBJECT

  Q_PROPERTY_STD_EX(QString, QAnyStringView, MKVToolnixPath);
  Q_PROPERTY_STD_EX(QString, QAnyStringView, StatusText);
  Q_PROPERTY_STD_EX(QString, QAnyStringView, TotalStatusText);
  Q_PROPERTY_STD(int, StatusProgress);
  Q_PROPERTY_STD(int, TotalStatusProgress);
  Q_PROPERTY_STD(bool, Extracting);
  Q_PROPERTY_STD(bool, UseSourceDirectory);
  Q_PROPERTY_STD(extract::chapter_types::ChapterTypes, ChapterType);
  public:
    explicit Model(
      extract::Logger *logger,
      extract::Helper *helper,
      SettingsManager *settingsManager,
      const std::function<void(QAnyStringView, QWidget *)> &showErrorMessage,
      extract::ExtractFactory &extractFactory,
      QObject *parent = nullptr
    );

    void parseCommandLineArguments(const QStringList &arguments);

    QStringList &filesFromCommandLine();

    extract::Logger &logger() const;

  public slots:

    void clearStatus();

  private:
    extract::Logger *m_logger;
    extract::Helper *m_helper;
    SettingsManager *m_settingsManager;
    extract::ExtractFactory &m_extractFactory;
    QScopedPointer<extract::Extract> m_extract;
    const std::function<void(QAnyStringView, QWidget *)> &m_showErrorMessage;
    QStringList m_filesFromCommandLine;

    void _createExtract();

    bool _setMKVToolnixPath(const QAnyStringView value, const bool check, const bool clearIfError, const bool showError);
  };
}
