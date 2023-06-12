#include "Settings.h"

namespace qmkv::model{
  Settings::Settings(QObject *parent)
      : QObject{parent}
  {

  }

  void Settings::setMkvToolnixPath(const QAnyStringView newMkvToolnixPath)
  {
    if(m_MkvToolnixPath == newMkvToolnixPath)
      return;
    m_MkvToolnixPath = newMkvToolnixPath.toString();
    emit MkvToolnixPathChanged(m_MkvToolnixPath);
  }

  void Settings::setChapterType(qmkv::extract::chapter_types::ChapterTypes newChapterType)
  {
    if(m_ChapterType == newChapterType)
      return;
    m_ChapterType = newChapterType;
    emit ChapterTypeChanged(m_ChapterType);
  }

  void Settings::setLockedOutputDirectory(bool newLockedOutputDirectory)
  {
    if(m_LockedOutputDirectory == newLockedOutputDirectory)
      return;
    m_LockedOutputDirectory = newLockedOutputDirectory;
    emit LockedOutputDirectoryChanged(m_LockedOutputDirectory);
  }

  void Settings::setDefaultOutputDirectory(QStringView newDefaultOutputDirectory)
  {
    if(m_DefaultOutputDirectory == newDefaultOutputDirectory)
      return;
    m_DefaultOutputDirectory = newDefaultOutputDirectory.toString();
    emit DefaultOutputDirectoryChanged(m_DefaultOutputDirectory);
  }

  void Settings::setOutputDirectory(QStringView newOutputDirectory)
  {
    if(m_OutputDirectory == newOutputDirectory)
      return;
    m_OutputDirectory = newOutputDirectory.toString();
    emit OutputDirectoryChanged(m_OutputDirectory);
  }

  void Settings::setWindowPosX(int32_t newWindowPosX)
  {
    if(m_WindowPosX == newWindowPosX)
      return;
    m_WindowPosX = newWindowPosX;
    emit WindowPosXChanged(m_WindowPosX);
  }

  void Settings::setWindowPosY(int32_t newWindowPosY)
  {
    if(m_WindowPosY == newWindowPosY)
      return;
    m_WindowPosY = newWindowPosY;
    emit WindowPosYChanged(m_WindowPosY);
  }

  void Settings::setWindowSizeWidth(int32_t newWindowSizeWidth)
  {
    if(m_WindowSizeWidth == newWindowSizeWidth)
      return;
    m_WindowSizeWidth = newWindowSizeWidth;
    emit WindowSizeWidthChanged(m_WindowSizeWidth);
  }

  void Settings::setWindowSizeHeight(int32_t newWindowSizeHeight)
  {
    if(m_WindowSizeHeight == newWindowSizeHeight)
      return;
    m_WindowSizeHeight = newWindowSizeHeight;
    emit WindowSizeHeightChanged(m_WindowSizeHeight);
  }

  void Settings::setJobMode(bool newJobMode)
  {
    if(m_JobMode == newJobMode)
      return;
    m_JobMode = newJobMode;
    emit JobModeChanged(m_JobMode);
  }

  void Settings::setWindowState(const qmkv::ui::FormWindowState newWindowState)
  {
    if(m_WindowState == newWindowState)
      return;
    m_WindowState = newWindowState;
    emit WindowStateChanged(m_WindowState);
  }

  void Settings::setShowPopup(bool newShowPopup)
  {
    if(m_ShowPopup == newShowPopup)
      return;
    m_ShowPopup = newShowPopup;
    emit ShowPopupChanged(m_ShowPopup);
  }

  void Settings::setShowPopupInJobManager(bool newShowPopupInJobManager)
  {
    if(m_ShowPopupInJobManager == newShowPopupInJobManager)
      return;
    m_ShowPopupInJobManager = newShowPopupInJobManager;
    emit ShowPopupInJobManagerChanged(m_ShowPopupInJobManager);
  }

  void Settings::setVideoTrackFilenamePattern(QStringView newVideoTrackFilenamePattern)
  {
    if(m_VideoTrackFilenamePattern == newVideoTrackFilenamePattern)
      return;
    m_VideoTrackFilenamePattern = newVideoTrackFilenamePattern.toString();
    emit VideoTrackFilenamePatternChanged(m_VideoTrackFilenamePattern);
  }

  constexpr auto _CommonTrackFilenamePattern{"{FilenameNoExt}_track{TrackNumber}_[{Language}]"};
  constexpr QLatin1StringView _VideoTrackFilenamePattern{_CommonTrackFilenamePattern};

  void Settings::resetVideoTrackFilenamePattern()
  {
    setVideoTrackFilenamePattern(_VideoTrackFilenamePattern.toString());
  }

  QStringView Settings::VideoTrackFilenamePattern() const
  {
    if(m_VideoTrackFilenamePattern.isNull()) {
      m_VideoTrackFilenamePattern = _VideoTrackFilenamePattern.toString();
    }
    return m_VideoTrackFilenamePattern;
  }

  constexpr QLatin1StringView _AudioTrackFilenamePattern{"{FilenameNoExt}_track{TrackNumber}_[{Language}]_DELAY {EffectiveDelay}ms"};

  QStringView Settings::AudioTrackFilenamePattern() const
  {
    if(m_AudioTrackFilenamePattern.isNull()) {
      m_AudioTrackFilenamePattern = _AudioTrackFilenamePattern.toString();
    }
    return m_AudioTrackFilenamePattern;
  }

  void Settings::setAudioTrackFilenamePattern(QStringView newAudioTrackFilenamePattern)
  {
    if(m_AudioTrackFilenamePattern == newAudioTrackFilenamePattern)
      return;
    m_AudioTrackFilenamePattern = newAudioTrackFilenamePattern.toString();
    emit AudioTrackFilenamePatternChanged(m_AudioTrackFilenamePattern);
  }

  void Settings::resetAudioTrackFilenamePattern()
  {
    setAudioTrackFilenamePattern(_AudioTrackFilenamePattern.toString());
  }

  constexpr QLatin1StringView _SubtitleTrackFilenamePattern{_CommonTrackFilenamePattern};

  QStringView Settings::SubtitleTrackFilenamePattern() const
  {
    if(m_SubtitleTrackFilenamePattern.isNull()) {
      m_SubtitleTrackFilenamePattern = _SubtitleTrackFilenamePattern.toString();
    }
    return m_SubtitleTrackFilenamePattern;
  }

  void Settings::setSubtitleTrackFilenamePattern(QStringView newSubtitleTrackFilenamePattern)
  {
    if(m_SubtitleTrackFilenamePattern == newSubtitleTrackFilenamePattern)
      return;
    m_SubtitleTrackFilenamePattern = newSubtitleTrackFilenamePattern.toString();
    emit SubtitleTrackFilenamePatternChanged(m_SubtitleTrackFilenamePattern);
  }

  void Settings::resetSubtitleTrackFilenamePattern()
  {
    setSubtitleTrackFilenamePattern(_SubtitleTrackFilenamePattern.toString());
  }

  constexpr QLatin1StringView _ChapterFilenamePattern{"{FilenameNoExt}_chapters"};

  QStringView Settings::ChapterFilenamePattern() const
  {
    if(m_ChapterFilenamePattern.isNull()) {
      m_ChapterFilenamePattern = _ChapterFilenamePattern.toString();
    }
    return m_ChapterFilenamePattern;
  }

  void Settings::setChapterFilenamePattern(QStringView newChapterFilenamePattern)
  {
    if(m_ChapterFilenamePattern == newChapterFilenamePattern)
      return;
    m_ChapterFilenamePattern = newChapterFilenamePattern.toString();
    emit ChapterFilenamePatternChanged(m_ChapterFilenamePattern);
  }

  void Settings::resetChapterFilenamePattern()
  {
    setChapterFilenamePattern(_ChapterFilenamePattern.toString());
  }


  constexpr QLatin1StringView _AttachmentFilenamePattern{"{AttachmentFilename}"};

  QStringView Settings::AttachmentFilenamePattern() const
  {
    if(m_AttachmentFilenamePattern.isNull()) {
      m_AttachmentFilenamePattern = _AttachmentFilenamePattern.toString();
    }
    return m_AttachmentFilenamePattern;
  }

  void Settings::setAttachmentFilenamePattern(QStringView newAttachmentFilenamePattern)
  {
    if(m_AttachmentFilenamePattern == newAttachmentFilenamePattern)
      return;
    m_AttachmentFilenamePattern = newAttachmentFilenamePattern.toString();
    emit AttachmentFilenamePatternChanged(m_AttachmentFilenamePattern);
  }

  void Settings::resetAttachmentFilenamePattern()
  {
    setAttachmentFilenamePattern(_AttachmentFilenamePattern.toString());
  }

  QAnyStringView Settings::MkvToolnixPath() const
  {
    return m_MkvToolnixPath;
  }


  qmkv::extract::chapter_types::ChapterTypes Settings::ChapterType() const
  {
    return m_ChapterType;
  }

  bool Settings::LockedOutputDirectory() const
  {
    return m_LockedOutputDirectory;
  }

  QStringView Settings::DefaultOutputDirectory() const
  {
    return m_DefaultOutputDirectory;
  }

  QStringView Settings::OutputDirectory() const
  {
    return m_OutputDirectory;
  }

  int32_t Settings::WindowPosX() const
  {
    return m_WindowPosX;
  }

  int32_t Settings::WindowPosY() const
  {
    return m_WindowPosY;
  }

  int32_t Settings::WindowSizeWidth() const
  {
    return m_WindowSizeWidth;
  }

  int32_t Settings::WindowSizeHeight() const
  {
    return m_WindowSizeHeight;
  }

  bool Settings::JobMode() const
  {
    return m_JobMode;
  }

  qmkv::ui::FormWindowState Settings::WindowState() const
  {
    return m_WindowState;
  }

  bool Settings::ShowPopupInJobManager() const
  {
    return m_ShowPopupInJobManager;
  }

  bool Settings::ShowPopup() const
  {
    return m_ShowPopup;
  }
}
