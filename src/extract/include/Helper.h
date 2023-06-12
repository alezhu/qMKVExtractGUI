#pragma once

#include <QLatin1StringView>

using namespace Qt::Literals::StringLiterals;

namespace qmkv::extract {
  class Helper {
  public:
    Helper();

    inline constexpr bool IsOnLinux() const noexcept
    {
#ifdef Q_OS_WIN
      return false;
#else
      return true;
#endif
    };

    inline constexpr QLatin1StringView MKV_MERGE_GUI_FILENAME() const noexcept
    {
#ifdef Q_OS_WIN
      return "mmg.exe"_L1;
#else
      return "mmg"_L1;
#endif
    };

    inline constexpr QLatin1StringView MKV_MERGE_NEW_GUI_FILENAME() const noexcept
    {
#ifdef Q_OS_WIN
      return "mkvmerge.exe"_L1;
#else
      return "mkvmerge"_L1;
#endif
    };

    QString UnescapeString(QString argString);

    QString EscapeString(QString argString);
  };
} // namespace qmkv::extract
