#pragma once

#include "qtmetamacros.h"
#include "qobjectdefs.h"

namespace qmkv::extract::chapter_types {
  Q_NAMESPACE
  enum class ChapterTypes : int {
    XML,
    OGM,
    CUE
  };

  Q_ENUM_NS(ChapterTypes)
}
