/*This drill simply involves getting the sequence of versions of Date to work. For each version define a Date called today
initialized to June 25, 1978. Then, define a Date called tomorrow and give it a value by copying today into it and
increasing its day by one using add_day(). Finally, output today and tomorrow using a << defined as in §9.8.
Your check for a valid date may be very simple. Feel free to ignore leap years. However, don’t accept a month that is not in
the [1,12] range or day of the month that is not in the [1,31] range. Test each version with at least one invalid date (e.g., 2004,
13, –5).
1. The version from §9.4.1
2. The version from §9.4.2
3. The version from §9.4.3
4. The version from §9.7.1
5. The version from §9.7.4
*/


//1. here I did the version from §9.4.1



#include "std_lib_facilities.h"

struct Date {
    int y, m, d;
};

void init_Date(Date& date, int y, int m, int d)
{
    if (d<=31 && d>0)
        date.d=d;
    else 
        error("invalid day");

    if (m<=12 && m>0)
        date.m=m;
    else
        error ("invalid month");
    if (y>0)
        date.y=y;
    else 
        error ("invalid year");

}

void add_day(Date& date, int n)
{
    date.d += n;
    if (date.d > 31)
    {
        date.m++;
        date.d -= 31;
        if (date.m >12)
        {
            date.y++;
            date.m -= 12;
        }
    }
    else if (date.d < 1)
    {
        date.m--;
        date.d += 31;
        if (date.m <1)
        {
            date.y--;
            date.m += 12;
        }
    }
}

int main()
try{
    Date today;                         //creating object as today
    init_Date(today, 1978, 6, 25);      //assigning date values

    Date tomorrow{today};               //creating tomorrow with date of today
    add_day(tomorrow, 1);               //using add_day constructor adding 1 day

    cout << "today: " << today.y << ". " << today.m << ". " << today.d << ".\n";                //printing out the date of today
    cout << "tomorrow: " << tomorrow.y << ". " << tomorrow.m << ". " << tomorrow.d << ".\n";    //printing out the date of tomorrow

//checking for date overflow;
    Date test2;
    init_Date(test2, 2005, 12, 31);
    add_day(test2, 2);
    cout << "overflow test date:" << test2.y << ". "<< test2.m << ". " << test2.d << "\n";
//checking for lowerflow;
    add_day(test2, -2);
    cout << "lowerflow test date:" << test2.y << ". "<< test2.m << ". " << test2.d << "\n";

// checking for invalid date
    Date test;
    init_Date(test, 2004, 13, -5);
    cout << "\n\n";

    
    return 0;

}

catch(exception& e)
{
    cerr << e.what() << "\n";
    return 1;
}
catch(...)
{
    cerr << "unknown error!!\n";
    return 2;
}