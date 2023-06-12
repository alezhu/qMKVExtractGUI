//
// Created by alezhu on 04.06.2023.
//

#pragma once

#include "Extract.h"

namespace qmkv::extract {
  class ExtractFactory {
  public:
    Extract *create(QAnyStringView path);
  };
}