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


//1. here I did the version from §9.4.4



#include "std_lib_facilities.h"

const vector<string> months = 
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
enum class Month {
	jan=0, feb, mar, apr, may, june, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m==Month::dec) ? Month::jan : Month(int(m)+1);		//added case for dec to jan
	return m;
}
Month operator--(Month& m)
{
	m = (m==Month::jan) ? Month::dec : Month(int(m)-1);		//added case for jan to dec
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date {
	int year;
	Month month;
	int day;
public:
	class Invalid {};
	Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }
	bool is_valid();
	void add_day(int n);
	int get_year(){ return year; }
	Month get_month(){ return month; }
	int get_day(){ return day; }
};

bool Date::is_valid()
{
	if (year < 0 || day < 1 || day > 31) return false;
	return true;
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		++month;
		day -= 31;
		if (month == Month::jan)			//checking if month has changed to jan then year should change
		{
			year++;
		}
	}
    
    else if (day < 1)
    {
        --month;
        day += 31;
        if (month == Month::dec)			//checking if month has changed to dec then year should change
        {
            year--;
        
        }
    }
}

int main()
try {
	cout << "let this is our today => ";
	Date today {2020, Month::aug, 31};

	cout << "Date: " << today.get_year() << ". " << today.get_month() << " " << today.get_day() << ".\n";

	today.add_day(1);
	cout << "checking for add day working or not\n tomorrow  => ";
	cout << "Date: " << today.get_year() << ". " << today.get_month() << " " << today.get_day() << ".\n";
	cout << "\n\n";


	//checking for years change by adding one day
	cout << "let this is our last day of year => ";
	Date my_birthday {2020,Month::dec,31};

	cout << "Date: " << my_birthday.get_year() << ". " << my_birthday.get_month() << " " << my_birthday.get_day() << ".\n";

	cout << "by adding one day to it => ";
	my_birthday.add_day(1);

	cout << "Date: " << my_birthday.get_year() << ". " << my_birthday.get_month() << " " << my_birthday.get_day() << ".\n";
	//checking for year change by subtracting one day
	cout << "by subtracting one day from it => ";
	my_birthday.add_day(-1);

	cout << "Date: " << my_birthday.get_year() << ". " << my_birthday.get_month() << " " << my_birthday.get_day() << ".\n";
	cout << "\n\n";


	//checking for invalid date
	cout << "here checking for an invalid date 2020,dec,35: ";
	Date invalid_date {2020,Month::dec,35};

	cout << "Date: " << invalid_date.get_year() << ". " << invalid_date.get_month() << " " << invalid_date.get_day() << ".\n";

	return 0;

} catch (Date::Invalid) {
	cout << "Error: Invalid date\n";
	return 1; 
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 2;
}