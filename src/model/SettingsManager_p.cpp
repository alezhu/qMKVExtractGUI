

#include "SettingsManager_p.h"
#include <QMetaProperty>
namespace qmkv::model
{

    SettingsManagerPrivate::SettingsManagerPrivate(extract::Logger& logger, QObject *parent)
        : QObject{parent},
          m_filter{logger, this},
          m_logger{logger}
    {
        m_storage.installEventFilter(&m_filter);
        _load();
        _connect();
    }

    Settings *SettingsManagerPrivate::get()
    {
        return &m_Settings;
    }

    void SettingsManagerPrivate::_connect()
    {
#pragma push_macro("qmkv_slot_connect")
#define qmkv_slot_connect(name) \
    QObject::connect(&m_Settings, &Settings::name##Changed, this, &SettingsManagerPrivate::on##name##Changed);

        //      QObject::connect(&m_Settings,&Settings::MkvToolnixPathChanged,this,&SettingsManager::onMkvToolnixPathChanged);
        qmkv_slot_connect(MkvToolnixPath);
        qmkv_slot_connect(ChapterType);
        qmkv_slot_connect(LockedOutputDirectory);
        qmkv_slot_connect(DefaultOutputDirectory);
        qmkv_slot_connect(OutputDirectory);
        qmkv_slot_connect(WindowPosX);
        qmkv_slot_connect(WindowPosY);
        qmkv_slot_connect(WindowSizeWidth);
        qmkv_slot_connect(WindowSizeHeight);
        qmkv_slot_connect(JobMode);
        qmkv_slot_connect(WindowState);
        qmkv_slot_connect(ShowPopup);
        qmkv_slot_connect(ShowPopupInJobManager);
        qmkv_slot_connect(VideoTrackFilenamePattern);
        qmkv_slot_connect(AudioTrackFilenamePattern);
        qmkv_slot_connect(AttachmentFilenamePattern);
        qmkv_slot_connect(ChapterFilenamePattern);
        qmkv_slot_connect(SubtitleTrackFilenamePattern);

#undef qmkv_slot_connect
#pragma pop_macro("qmkv_slot_connect")
    }
    void SettingsManagerPrivate::_load()
    {
        m_logger.log(tr("Begin loading settings..."));

        auto meta = m_Settings.metaObject();
        auto count = meta->propertyCount();
        for (int i = 0; i < count; i++)
        {
            auto property = meta->property(i);
            QAnyStringView name(property.name());
            if (m_storage.contains(name))
            {
                auto value = m_storage.value(name);
                if (!m_Settings.setProperty(property.name(), value))
                {
                  auto msg = tr("Error reading %1!: %2").arg(property.name(),value.toString());
                  qDebug() << msg;
                  m_logger.log(msg);
                };
            }
        }

        m_logger.log(tr("Finished loading settings!"));
    }

    void SettingsManagerPrivate::onMkvToolnixPathChanged(QStringView value)
    {
        m_storage.setValue("MkvToolnixPath", value.toString());
    }

    void SettingsManagerPrivate::onChapterTypeChanged(extract::ChapterTypes value)
    {
        m_storage.setValue("ChapterType", static_cast<int>(value));
    }

    void SettingsManagerPrivate::onLockedOutputDirectoryChanged(bool value)
    {
        m_storage.setValue("LockedOutputDirectory", value);
    }

    void SettingsManagerPrivate::onDefaultOutputDirectoryChanged(QStringView value)
    {
        m_storage.setValue("DefaultOutputDirectory", value.toString());
    }

    void SettingsManagerPrivate::onOutputDirectoryChanged(QStringView value)
    {
        m_storage.setValue("OutputDirectoryy", value.toString());
    }

    void SettingsManagerPrivate::onWindowPosXChanged(int32_t value)
    {
        m_storage.setValue("WindowPosX", value);
    }

    void SettingsManagerPrivate::onWindowPosYChanged(int32_t value)
    {
        m_storage.setValue("WindowPosY", value);
    }

    void SettingsManagerPrivate::onWindowSizeWidthChanged(int32_t value)
    {
        m_storage.setValue("WindowSizeWidth", value);
    }

    void SettingsManagerPrivate::onWindowSizeHeightChanged(int32_t value)
    {
        m_storage.setValue("WindowSizeHeight", value);
    }

    void SettingsManagerPrivate::onJobModeChanged(bool value)
    {
        m_storage.setValue("JobMode", value);
    }

    void SettingsManagerPrivate::onWindowStateChanged(const ui::FormWindowState value)
    {
        m_storage.setValue("WindowState", static_cast<int>(value));
    }

    void SettingsManagerPrivate::onShowPopupChanged(bool value)
    {
        m_storage.setValue("ShowPopup", value);
    }

    void SettingsManagerPrivate::onShowPopupInJobManagerChanged(bool value)
    {
        m_storage.setValue("ShowPopupInJobManager", value);
    }

    void SettingsManagerPrivate::onVideoTrackFilenamePatternChanged(QStringView value)
    {
        m_storage.setValue("VideoTrackFilenamePattern", value.toString());
    }

    void SettingsManagerPrivate::onAudioTrackFilenamePatternChanged(QStringView value)
    {
        m_storage.setValue("AudioTrackFilenamePattern", value.toString());
    }

    void SettingsManagerPrivate::onAttachmentFilenamePatternChanged(QStringView value)
    {
        m_storage.setValue("AttachmentFilenamePattern", value.toString());
    }

    void SettingsManagerPrivate::onChapterFilenamePatternChanged(QStringView value)
    {
        m_storage.setValue("ChapterFilenamePattern", value.toString());
    }

    void SettingsManagerPrivate::onSubtitleTrackFilenamePatternChanged(QStringView value)
    {
        m_storage.setValue("SubtitleTrackFilenamePattern", value.toString());
    }
}
