#include <QDir>
#include "path.h"

namespace qmkv::core {
  QString pathCombine(QAnyStringView path1, QAnyStringView path2)
  {
    auto result = QDir::cleanPath(path1.toString() + QDir::separator() + path2.toString());
    return result;
  }
}