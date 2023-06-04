// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com//
// Created by alezhu on 03.06.2023.
//

#include <QDir>
#include "Extract.h"
#include "path.h"
#include <QLatin1StringView>

using namespace Qt::Literals::StringLiterals;
namespace qmkv::extract {
    Extract::Extract(QAnyStringView mkvToonlixPath)
            : m_mkvToonlixPath{mkvToonlixPath.toString()},
              m_MKVExtractFilename{core::pathCombine(m_mkvToonlixPath, MKV_EXTRACT_FILENAME())} {
    }

    QLatin1StringView Extract::MKV_EXTRACT_FILENAME() {
#ifdef  Q_OS_WIN
        return "mkvextract.exe"_L1;
#else
        return "mkvextract"_L1;
#endif

    }
}
