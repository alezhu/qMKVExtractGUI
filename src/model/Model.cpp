#include <QFile>
#include "include\Model.h"
#include "path.h"

namespace qmkv::model {
    Model::Model(
            extract::Logger *logger,
            extract::Helper *helper,
            SettingsManager *settingsManager,
            const std::function<void(QAnyStringView, QWidget *)> &showErrorMessage,
            extract::ExtractFactory &extractFactory,
            QObject *parent)
            : QObject(parent),
              m_logger{logger},
              m_helper{helper},
              m_settingsManager{settingsManager},
              m_extractFactory{extractFactory},
              m_showErrorMessage{showErrorMessage} {

        auto path = m_settingsManager->get()->MkvToolnixPath();
        if (!path.isEmpty()) {
            setMKVToolnixPath(path);
        }
        _createExtract();
        connect(this, &Model::MKVToolnixPathChanged, this, &Model::_createExtract);

    }

    QStringView Model::MKVToolnixPath() const {
        return m_MKVToolnixPath;
    }

    void Model::setMKVToolnixPath(const QStringView value) {
        _setMKVToolnixPath(value, true, true, true);
    }

    bool Model::_setMKVToolnixPath(const QStringView value, const bool check, const bool clearIfError,
                                   const bool showError) {
        if (m_MKVToolnixPath == value) return true;
        auto path = value.trimmed().toString();
        auto result = true;
        if (check) {
            if (!QFile(core::pathCombine(path, m_helper->MKV_MERGE_GUI_FILENAME())).exists()
                && !QFile(core::pathCombine(path, m_helper->MKV_MERGE_NEW_GUI_FILENAME())).exists()
                    ) {
                path.clear();
                auto msg = tr("The folder does not contain MKVToolnix!");
                m_logger->log(msg);
                qDebug() << msg;
                if (showError) {
                    m_showErrorMessage(msg, nullptr);
                }
                if (clearIfError) return false;
                result = false;
            }
        }
        m_settingsManager->get()->setMkvToolnixPath(path);
        m_logger->log(tr("Changing MkvToolnixPath"));

        if (m_MKVToolnixPath == value) return result;
        m_MKVToolnixPath = path;
        emit MKVToolnixPathChanged(m_MKVToolnixPath);
        return result;
    }

    void Model::_createExtract() {
        m_extract.reset(m_extractFactory.create(MKVToolnixPath()));
    }


}
