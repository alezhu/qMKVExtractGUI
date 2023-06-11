
#pragma once

#include "ChapterTypes.h"
#include "common.h"
#include <QObject>

namespace qmkv::model
{
  class Settings : public QObject
  {
    Q_OBJECT
    Q_PROPERTY_STD_EX(QString, QStringView, OutputDirectory)
    Q_PROPERTY_STD_EX(QString, QStringView, DefaultOutputDirectory)
    Q_PROPERTY_STD_EX(QString,QStringView, MkvToolnixPath)
    Q_PROPERTY_STD(qmkv::ui::FormWindowState, WindowState)
    Q_PROPERTY_STD(bool, LockedOutputDirectory)
    Q_PROPERTY_STD(bool, JobMode)
    Q_PROPERTY_STD(bool, ShowPopup)
    Q_PROPERTY_STD(bool, ShowPopupInJobManager)
    Q_PROPERTY_STD(int32_t, WindowPosX)
    Q_PROPERTY_STD(int32_t, WindowPosY)
    Q_PROPERTY_STD(int32_t, WindowSizeWidth)
    Q_PROPERTY_STD(int32_t, WindowSizeHeight)

    Q_PROPERTY_STD_RESET_EX(QString,QStringView, VideoTrackFilenamePattern)
    Q_PROPERTY_STD_RESET_EX(QString,QStringView, AudioTrackFilenamePattern)
    Q_PROPERTY_STD_RESET_EX(QString,QStringView, SubtitleTrackFilenamePattern)
    Q_PROPERTY_STD_RESET_EX(QString,QStringView, ChapterFilenamePattern)
    Q_PROPERTY_STD_RESET_EX(QString,QStringView, AttachmentFilenamePattern)
  Q_PROPERTY_STD(qmkv::extract::chapter_types::ChapterTypes, ChapterType)

  public:
    explicit Settings(QObject *parent = nullptr);

  };

} // namespace qmkv::model
