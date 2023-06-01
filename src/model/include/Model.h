#pragma once

#include <QObject>
namespace qmkv::model
{
    class Model : public QObject
    {
        Q_OBJECT
    public:
        explicit Model(QObject *parent = nullptr);

    signals:
    };
}