#include <hw05.h>

VecOfStr hw05(const VecOfStr& strings)
{
  VecOfStr Denisiki_polyndroms;

  auto is_Denisik = [](const string& denisik) {
    auto start = denisik.begin();
    auto end = denisik.rbegin();

    while (start != denisik.end() && end != denisik.rend()) {
      while (start != denisik.end() && !isalnum(*start)) {
        ++start;
      }
      while (end != denisik.rend() && !isalnum(*end)) {
        ++end;
      }
      if (start == denisik.end() || end == denisik.rend()) {
        break;
      }
      if (tolower(*start) != tolower(*end)) {
        return false;
      }
      ++start;
      ++end;
    }
    return true;
  };

  for (const auto& denisik : strings) {
    if (is_Denisik(denisik)) {
      Denisiki_polyndroms.push_back(denisik);
    }
  }

  return Denisiki_polyndroms;
}
