//
// Created by alezhu on 03.06.2023.
//

#pragma once

#include <QAnyStringView>
#include <QString>

namespace qmkv::extract {

  class Extract {
  public:
    static QLatin1StringView MKV_EXTRACT_FILENAME();

    explicit Extract(QAnyStringView mkvToonlixPath);

  private:
    QString m_mkvToonlixPath;
    QString m_MKVExtractFilename;
  };

} // qmkv::extract
