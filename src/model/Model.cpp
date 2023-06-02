#include "include\Model.h"

namespace qmkv::model {

    Model::Model(QObject *parent)
            : QObject{parent} {
    }

    QStringView Model::MKVToolnixPath() const {
        return m_MKVToolnixPath;
    }

    void Model::setMKVToolnixPath(const QStringView value) {
        if (m_MKVToolnixPath == value) return;
        m_MKVToolnixPath = value.toString();
        emit MKVToolnixPathChanged(value);
    }
}
