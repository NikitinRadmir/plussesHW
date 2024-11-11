#include <hw01.h>

int hw01(int start, int end)
{
  if (start < 10 || start > 99 || end < 10 || end > 99 || start > end) {
    return -1;
  }

  int result = 0;
  for (int i = start; i <= end; ++i) {
    bool flag = true;
    if (i < 2) flag = false;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }

    if (flag) {
      int sum = 0;
      int number = i;
      while (number > 0) {
        sum += number % 10;
        number /= 10;
      }
      result += sum;
    }
  }

  return result;
}
