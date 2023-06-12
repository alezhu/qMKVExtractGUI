#include <QFile>
#include <QCommandLineParser>
#include <QDir>
#include "include\Model.h"
#include "path.h"

namespace qmkv::model {
  Model::Model(
    extract::Logger *logger,
    extract::Helper *helper,
    SettingsManager *settingsManager,
    const std::function<void(QAnyStringView, QWidget *)> &showErrorMessage,
    extract::ExtractFactory &extractFactory,
    QObject *parent
  ) :
    QObject(parent),
    m_logger{logger},
    m_helper{helper},
    m_settingsManager{settingsManager},
    m_extractFactory{extractFactory},
    m_showErrorMessage{showErrorMessage},
    m_Extracting{false}
  {

    auto settings = m_settingsManager->get();
    auto path = settings->MkvToolnixPath();
    if(!path.isEmpty()) {
      _setMKVToolnixPath(path, true, false, false);
    }

    m_ChapterType = settings->ChapterType();

    _createExtract();
    connect(this, &Model::MKVToolnixPathChanged, this, &Model::_createExtract);

  }

  QAnyStringView Model::MKVToolnixPath() const
  {
    return m_MKVToolnixPath;
  }

  void Model::setMKVToolnixPath(const QAnyStringView value)
  {
    _setMKVToolnixPath(value, true, true, true);
  }

  bool Model::_setMKVToolnixPath(
    const QAnyStringView value, const bool check, const bool clearIfError, const bool showError
  )
  {
    if(m_MKVToolnixPath == value) return true;
    auto path = value.toString().trimmed();
    auto result = true;
    if(check) {
      if(!QFile(core::pathCombine(path, m_helper->MKV_MERGE_GUI_FILENAME())).exists()
         && !QFile(core::pathCombine(path, m_helper->MKV_MERGE_NEW_GUI_FILENAME())).exists()) {
        auto msg = tr("The folder does not contain MKVToolnix!");
        m_logger->log(msg);
        qDebug() << msg;
        if(showError) {
          m_showErrorMessage(msg, nullptr);
        }
        if(!clearIfError) return false;
        path.clear();
        result = false;
      }
    }
    m_settingsManager->get()->setMkvToolnixPath(path);
    m_logger->log(tr("Changing MkvToolnixPath"));

    if(m_MKVToolnixPath == value) return result;
    m_MKVToolnixPath = path;
    emit MKVToolnixPathChanged(m_MKVToolnixPath);
    return result;
  }

  void Model::_createExtract()
  {
    m_extract.reset(m_extractFactory.create(MKVToolnixPath()));
  }

  void Model::parseCommandLineArguments(const QStringList &arguments)
  {
    auto args = arguments.join(',');
    auto msg = QString(tr("Found command line arguments: %1")).arg(args);
    m_logger->log(msg);

    QCommandLineParser parser;
    QString mkvtoolnixName("mkvtoolnix");
    QCommandLineOption mkvtoolnixOption{mkvtoolnixName};
    mkvtoolnixOption.setValueName(mkvtoolnixName);

    parser.addOption(mkvtoolnixOption);
    parser.process(arguments);

    auto mkvtoolnixValue = parser.value(mkvtoolnixOption);
    if(!mkvtoolnixValue.isEmpty()) {
      m_logger->log(QString(tr("User provided a manual path for MKVToolNix: %1")).arg(mkvtoolnixValue));
      QDir manualPath(mkvtoolnixValue);
      if(!manualPath.exists()) {
        m_logger->log(tr("The manual path for MKVToolNix does not exist!"));
      }
      else {
        auto result = _setMKVToolnixPath(mkvtoolnixValue, true, false, false);
        if(!result) {
          m_logger->log(tr("Failed to set manual path!"));
        }
      }
    }

    m_filesFromCommandLine = parser.positionalArguments();
  }

  QStringList &Model::filesFromCommandLine()
  {
    return m_filesFromCommandLine;
  }

  bool Model::Extracting() const
  {
    return m_Extracting;
  }

  void Model::setExtracting(const bool value)
  {
    if(m_Extracting == value) return;
    m_Extracting = value;
    emit ExtractingChanged(m_Extracting);
  }

  extract::chapter_types::ChapterTypes Model::ChapterType() const
  {
    return m_ChapterType;
  }

  void Model::setChapterType(const extract::chapter_types::ChapterTypes value)
  {
    if(m_ChapterType == value) return;
    m_ChapterType = value;
    m_settingsManager->get()->setChapterType(value);
    m_logger->log(tr("Changing ChapterType"));

    emit ChapterTypeChanged(value);
  }
  QAnyStringView Model::StatusText() const
  {
    return m_StatusText;
  }

  void Model::setStatusText(const QAnyStringView value)
  {
    if(m_StatusText == value) return;
    m_StatusText = value.toString();
    emit StatusTextChanged(value);
  }
}
