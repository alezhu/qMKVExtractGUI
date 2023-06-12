// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com//
// Created by alezhu on 04.06.2023.
//

#include "ExtractFactory.h"

namespace qmkv::extract {
  Extract *ExtractFactory::create(QAnyStringView path)
  {
    return new Extract(path);
  }
}
