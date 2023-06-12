//
// Created by alezhu on 10.06.2023.
//

#pragma once

#include "qtmetamacros.h"
#include "qobjectdefs.h"

namespace qmkv::extract::extraction_mode {
  Q_NAMESPACE
  enum class ExtractionMode : int {
    Tracks, Cue_Sheet, Tags, Timecodes, Tracks_And_Timecodes, Cues, Tracks_And_Cues, Tracks_And_Cues_And_Timecodes
  };

  Q_ENUM_NS(ExtractionMode)
}