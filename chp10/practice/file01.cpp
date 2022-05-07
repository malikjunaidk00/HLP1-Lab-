#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temp;
};

int main()
{
	string ifname;
	cout << "please enter an input filename: ";
	cin >> ifname;		// storing the name of file in string
	ifstream ifs { ifname };	//getting data from file
	int h = 0;
	double t = 0.0;

	vector <Reading> temps;

	while (ifs >> h >> t )		//while we get data from the file
	{
		//cout << "Hour: "<< h << " 	temp: " << t << endl;
		temps.push_back(Reading{h, t});		//copying data into the vector
	};
	for (const auto& t: temps)			//printing out the data stored in the vector
		cout << "Hour: "<< t.hour << " 	temp: " << t.temp << endl;
	
	return 0;
}