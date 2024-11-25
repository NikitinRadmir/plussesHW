#include <hw02.h>

std::string hw02(std::string input_str)
{
  std::string result;
  for (char ch : input_str) {
    if (result.find(ch) == std::string::npos) {
      result += ch;
    }
  }

  return result;
}
