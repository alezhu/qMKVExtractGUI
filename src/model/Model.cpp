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
              m_showErrorMessage{showErrorMessage} {

    }

    QStringView Model::MKVToolnixPath() const {
        return m_MKVToolnixPath;
    }

    void Model::setMKVToolnixPath(const QStringView value) {
        if (m_MKVToolnixPath == value) return;
        auto path = value.trimmed().toString();

        if (!QFile(core::pathCombine(path, m_helper->MKV_MERGE_GUI_FILENAME())).exists()
            && !QFile(core::pathCombine(path, m_helper->MKV_MERGE_NEW_GUI_FILENAME())).exists()
                ) {
            path.clear();
            auto msg = tr("The folder does not contain MKVToolnix!");
            m_logger->log(msg);
            qDebug() << msg;
            m_showErrorMessage(msg, nullptr);
        } else {
            m_settingsManager->get()->setMkvToolnixPath(path);
            m_logger->log(tr("Changing MkvToolnixPath"));
        }

        m_MKVToolnixPath = path;
        emit MKVToolnixPathChanged(m_MKVToolnixPath);
    }
}
