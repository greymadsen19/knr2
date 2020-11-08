#include <stdio.h>

int main(void) {
  int day_of_year(int, int, int);
  void month_day(int, int, int *, int *);

  int yearday;
  int day;
  int month;
  int year;

  year = 2014;
  month = 14;
  day = 29;


  if ((yearday = day_of_year(year, month, day)) < 0) {
    printf("error: invalid date.\n");
  }
  else {
    printf("Day of year: %d\n", yearday);
  }

  // set month to a valid value
  month = 2;
  yearday = day_of_year(year, month, day);
  if (yearday < 0)
    printf("invalid date\n");
  else
    printf("Day of year: %d\n", yearday);

  // Set month and day from year
  // where year is 2007

  year = 2007;

  month_day(year, yearday, &month, &day);

  printf("Year: %d\n", year);
  printf("Month: %d\n", month);
  printf("Day: %d\n", day);

  return 0;
}
