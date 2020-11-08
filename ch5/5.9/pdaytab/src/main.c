#include <stdio.h>

int main(void) {
  int day_of_year(int, int, int);
  void month_day(int, int, int *, int *);

  int year;
  int month;
  int day;
  int yearday;
  
  year = 2008;
  month = 2;
  day = 29;

  yearday = day_of_year(year, month, day);

  printf("Day of year: %d\n", yearday);

  month_day(year, yearday, &month, &day);

  printf("Year: %d\n", year);
  printf("Month: %d\n", month);
  printf("Day: %d\n", day);

  return 0;
}
