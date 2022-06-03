#include "s21_sprintf.h"

void s21_proc_float(t_flags *flags, double x,  char *buf) {
    int count = 0;
    int flag = 0;

    while (count != 6) {
    x *= 10;
    count++;}
    x = (float)x;
    s21_proc_int(flags, x, buf);
    char str1[100];

    for (size_t i = 0; i < s21_strlen(buf)+1; i++) {
      str1[i] = buf[i - flag];
      if (i == s21_strlen(buf) - count && flag == 0) {
        str1[i] = '.';
        flag = 1;}
    }

    for (size_t i = 0; i < s21_strlen(str1); i++) {
        buf[i] = str1[i];
    }
    }