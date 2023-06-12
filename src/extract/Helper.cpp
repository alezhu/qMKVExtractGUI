#include "Helper.h"
#include <QtGlobal>

namespace qmkv::extract {
  Helper::Helper() {}

  constexpr std::array<std::pair<QLatin1StringView, QLatin1StringView>, 7>
    escape_pairs = {{
                      {R"(\s)"_L1, " "_L1},
                      {R"(\2)"_L1, "\""_L1},
                      {R"(\c)"_L1, ":"_L1},
                      {R"(\h)"_L1, "#"_L1},
                      {R"(\\)"_L1, "\\"_L1}, //????
                      {R"(\b)"_L1, "["_L1},
                      {R"(\B)"_L1, "]"_L1},
                    }};

  QString processPairs(
    QString str,
    std::function<QString(QString, const std::pair<QLatin1StringView, QLatin1StringView> &)> fn
  )
  {
    auto result = str;
    for(auto &&pair: escape_pairs) {
      result = fn(result, pair);
    }
    return result;
  }

  QString Helper::UnescapeString(QString argString)
  {
    auto result = processPairs(argString, [](auto str, auto pair) { return str.replace(pair.first, pair.second); });
    return result;
  }

  QString Helper::EscapeString(QString argString)
  {
    auto result = processPairs(argString, [](auto str, auto pair) { return str.replace(pair.second, pair.first); });
    return result;
  }

} // namespace qmkv::extract
