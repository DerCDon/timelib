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
int day_of_the_year(int day, int month, int year)
{
    int i;
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0;

    printf(" *** Tag des Jahres ***\n");

    while(1)
    {
        printf("Tag:");
        scanf("%i",&day);
        printf("Monat:");
        scanf("%i",&month);
        printf("Jahr:");
        scanf("%i",&year);
        if (month == 2)
        {
            if (schaltjahr(year) == 1)
            {
                if(day > 29)
                {
                    printf("Ungueltiger Tag\n");
                    continue;
                }
            }

        }
        if (day > days_per_month[month +1])
        {
            printf("Ungueltiger Tag\n");
                            continue;
        }
        if (month > 12)
        {
            printf("Ungueltiger Monat\n");
                            continue;
        }
        break;
    }
    if (month>1)
    {
        for(i=0; i< month-1; i++)
        {
            if(schaltjahr(year) == 1)
            {
                days_per_month[1] = 29;
            }
            days += days_per_month[i];
        }
        days += day;

    }
    else
    {
        days = day;
    }
    printf("Der %i.%i.%i ist der %i. des Jahres",day,month,year,days);


    return 0;
}

int schaltjahr(int year)
{
    if (year%4 == 0)
    {
        if (year%100 != 0 || year%400 == 0)
        {
            return 1;
        }
    }
    return 0;

}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
