#pragma once

#include <QObject>
#include "common.h"

namespace qmkv::model
{
    class Model : public QObject
    {
        Q_OBJECT
    public:
        explicit Model(QObject *parent = nullptr);

        Q_PROPERTY_STD_EX(QString, QStringView, MKVToolnixPath);

    };
}
