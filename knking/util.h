#ifndef KNKING_UTIL_H
#define KNKING_UTIL_H

#include <stdbool.h>

bool is_leap(int yr);

int get_month_days(int yr, int mnth);

int gcd(int a, int b);

int read_line(char str[], int n);

#endif