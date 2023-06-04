#pragma once

#include <QObject>
#include "common.h"
#include "SettingsManager.h"
#include "Helper.h"
#include "ExtractFactory.h"

namespace qmkv::model {
    class Model : public QObject {
    Q_OBJECT

    public:
        explicit Model(
                extract::Logger *logger,
                extract::Helper *helper,
                SettingsManager *settingsManager,
                const std::function<void(QAnyStringView, QWidget *)> &showErrorMessage,
                QObject *parent = nullptr);

    Q_PROPERTY_STD_EX(QString, QStringView, MKVToolnixPath);

    private:
        extract::Logger *m_logger;
        extract::Helper *m_helper;
        SettingsManager *m_settingsManager;
        const std::function<void(QAnyStringView, QWidget *)> &m_showErrorMessage;
    };
}
