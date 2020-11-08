static char daytab[2][13]  = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char (*pdaytab)[13] = daytab;

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  for (i = 1; i < month; i++)
    day += *( *(pdaytab + leap) + i);

  return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  for (i = 1; yearday > *( *(pdaytab + leap) + i); i++)
    yearday -= *( *(pdaytab + leap) + i);

  *pmonth = i;

  *pday = yearday;
}
