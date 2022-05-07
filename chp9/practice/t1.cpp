// 9.drill.02.cpp
//
//  This drill simply involves getting the sequence of versions of Date to
//  work. For each version define a Date called today initialized to June 25,
//  1978. Then, define a Date called tomorrow and give it a value by copying
//  today into it and increasing its day by one using add_day(). Finally,
//  output today and tomorrow using a << defined as in §9.8.
//  Your check for a valid date may be very simple. Feel free to ignore leap
//  years. However, don't accept a month that is not in the [1,12] range or
//  day of the month that is not in the [1,31] range. Test each version with at
//  least one invalid date (e.g., 2004, 13, -5).
//
//  The version from §9.4.2
//
// COMMENTS
//
//  I will not do this by separating Date class, Month enumerator or helper
//  functions in their own header file. Just for the shake of simplicity.
//
//  §9.4.2 do not explicitly explain member how to define memeber function for
//  a class (or struct), so we have to borrow it from elsewhere.
//
//  Date::add_day() will be implemented supposing all months have 31 days. It will
//  complicate it to do better until best tools, as enums, are introduced.

#include "std_lib_facilities.h"

struct Date {
    int y, m, d;                    // year, month, day
    Date(int yy, int mm, int dd);   // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
};

Date::Date(int yy, int mm, int dd)
// Simply (and incorrect) date constructor with simply (and incorrect) checks.
{
    if (dd < 1 || dd > 31) error("init_day: Invalid day");
    if (mm < 1 || mm > 12) error("init_day: Invalid month");

    y = yy;       // We don't check valid year yet
    m = mm;
    d = dd;
}

void Date::add_day(int n)
// Function to add or substract days from a Date.
{
    d += n;
     
    // We must check for overflows, and n can be negative!!
    if (d > 31) { ++m; d -= 31; }     // Day overflow
    if (d < 1)  { --m; d += 31; }     // Day underflow
    // We have modified month, so we must check it
    if (m > 12) { ++y; m -= 12; }     // Month overflow
    if (m < 1)  { --y; m += 12; }     // Month underfow
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

int main()
try
{
    Date today{1978, 6, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    // Check add_day() overflow (far from perfect) detection 
    Date test{2010, 12, 31};

    test.add_day(7);   // 2011 January 6th
    cout << "January the 6th 2011? " << test << '\n';
    test.add_day(-6);  // 2010 December 31st again
    cout << "December the 31st 2010? " << test << '\n';

    test = Date{2010, 2, 5};
    test.add_day(-7);   // 2010 January 29th 
    cout << "January the 29th 2010? " << test << '\n';
    test.add_day(7);    // 2010 February 5th again 
    cout << "February the 5th 2010? " << test << '\n';

    // Invalid date
    Date today_e{2004, 13, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}