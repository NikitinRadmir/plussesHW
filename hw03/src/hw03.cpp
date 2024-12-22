#include <hw03.h>
#include<iostream>
#include<cstring>
using namespace std;
void hw03(char* str, const char* pattern) {
  if (str == nullptr || pattern == nullptr) {
    return;
  }

  size_t str_len = strlen(str);
  size_t pattern_len = strlen(pattern);

  if (str_len == 0 || pattern_len == 0 || pattern_len > str_len) {
    return;
  }

  char* found = strstr(str, pattern);
  if (found == nullptr) {
    return;
  }

  // Перемещаем часть строки после найденной подстроки на длину подстроки влево
  memmove(found, found + pattern_len, str_len - (found - str) - pattern_len + 1);
}
