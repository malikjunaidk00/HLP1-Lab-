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


//1. here I did the version from §9.4.3



#include "std_lib_facilities.h"

class Date {
	int year, month, day;
public:
	Date(int y, int m, int d);
	void add_day(int n);
	int get_year(){ return year; }
	int get_month(){ return month; }
	int get_day(){ return day; }
};

Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;
	else
		error("Invalid year");
	if (m < 13 && m > 0)
		month = m;
	else
		error("Invalid month");
	if (d > 0 && d < 32)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
    else if (day < 1)
    {
        month--;
        day += 31;
        if (month <1)
        {
            year--;
            month += 12;
        }
    }
}

int main()
try {
	Date today {1978, 6, 25}; // assigning date as today

    

	cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";

    Date tomorrow {today};

	tomorrow.add_day(1);

	cout << "Date: " << tomorrow.get_year() << ". " << tomorrow.get_month() << ". " << tomorrow.get_day() << ".\n";
//checking for date overflow;
    Date test1 {2005, 12, 31};
	cout << "test1 Date: " << test1.get_year() << ". " << test1.get_month() << ". " << test1.get_day() << ".\n";
    test1.add_day(4);
    cout << "test1 overflow Date: " << test1.get_year() << ". " << test1.get_month() << ". " << test1.get_day() << ".\n";
//checking for lowerflow;
    test1.add_day(-4);
    cout << "test1 lowerflow Date: " << test1.get_year() << ". " << test1.get_month() << ". " << test1.get_day() << ".\n";
//checking for invalid date
    Date test2 {2004, 13, -5};
    cout << "test2 date:"<< test2.get_year() << ". " << test2.get_month() << ". " << test2.get_day() << ". " << endl;
	return 0;

} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
}
catch (...) {
    cerr << "unknown error!!\n";
    return 2;
}