#pragma once
#include "SettingsManager_p.h"
#include "Settings.h"
#include "SettingsFilter.h"
#include <Logger.h>
#include <QSettings>

namespace qmkv::model
{

  class SettingsManagerPrivate : public QObject
  {
    Q_OBJECT
  public:
    explicit SettingsManagerPrivate(extract::Logger& logger, QObject *parent = nullptr);
    virtual ~SettingsManagerPrivate() = default;

    Settings *get();

  private:
    Settings m_Settings;
    QSettings m_storage;
    SettingsFilter m_filter;
    extract::Logger& m_logger;

    void _load();
    void _connect();

  private slots:
    void onMkvToolnixPathChanged(QStringView value);

    void onChapterTypeChanged(qmkv::extract::ChapterTypes value);

    void onLockedOutputDirectoryChanged(bool value);

    void onDefaultOutputDirectoryChanged(QStringView value);

    void onOutputDirectoryChanged(QStringView value);

    void onWindowPosXChanged(int32_t value);

    void onWindowPosYChanged(int32_t value);

    void onWindowSizeWidthChanged(int32_t value);

    void onWindowSizeHeightChanged(int32_t value);

    void onJobModeChanged(bool value);

    void onWindowStateChanged(const qmkv::ui::FormWindowState value);

    void onShowPopupChanged(bool value);

    void onShowPopupInJobManagerChanged(bool value);

    void onVideoTrackFilenamePatternChanged(QStringView value);

    void onAudioTrackFilenamePatternChanged(QStringView value);

    void onAttachmentFilenamePatternChanged(QStringView value);

    void onChapterFilenamePatternChanged(QStringView value);

    void onSubtitleTrackFilenamePatternChanged(QStringView value);
  };
}
