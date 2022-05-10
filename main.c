/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
 struct date
 {
     int year;
     int month;
     int day;

 };

 int is_leapyear(struct date date)
 {
    if (date.year <1582)
    {
        return -1;
    }
    if (date.year%4 == 0)
    {
        if (date.year%100 != 0 || date.year%400 == 0)
        {
            return 1;
        }
    }
    return 0;
 }

 int get_days_for_month(struct date date, int month)
 {
     int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
     int days_per_month_in_leapyear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
     if (is_leapyear(date))
     {
         return days_per_month_in_leapyear[month-1];
     }
     else
     {
         return days_per_month[month-1];
     }

 }
 int exists_date(struct date date)
 {
     if (date.day > get_days_for_month(date,date.month))
     {
         return 0;
     }

     if ((date.month<=0) || (date.month >12))
     {
         return 0;
     }
     if ((date.year <1582) || (date.year > 2400))
     {
         return 0;
     }

    return 1;

 }

 int day_of_the_year(struct date date)
 {
     int total_days = 0;
     int i;
     for (i=1;i<date.month;i++)
     {
         total_days += get_days_for_month(date,i);

     }
     total_days += date.day;
     return total_days;
 }

 struct date input_date()
 {
     struct date date;
     while(1)
     {
         printf("Geben Sie ein Jahr ein: \n");
         scanf("%d", &date.year);

         printf("Geben Sie einen Monat ein: \n");
         scanf("%d", &date.month);
         printf("Geben Sie einen Tag ein: \n");
         scanf("%d", &date.day);

         if(exists_date(date) == 1)
         {
             break;
         }
         else
         {
             printf("Falsche Eingabe \n");
         }
     }
     return date;

 }

int main()
{
    struct date date1;
    date1 = input_date();
    printf("Day of the Year: %d", day_of_the_year(date1));
    return 0;
}

