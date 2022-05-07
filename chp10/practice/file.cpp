#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temp;
};

int main()
try{
	string ifname , ofname;
	cout << "please enter an input filename: ";
	cin >> ifname;		// storing the name of file in string

	ifstream ifs { ifname };	//getting data from file
	
	if (!ifs) error("Cannot open ifs.", ifname);

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

	cout << "please enter an output filename: ";
	cin >> ofname;		// storing the name of output file in string

	ofstream ofs {ofname};

	if (!ofs) error("Cannot open ofs.", ofname);

	for (const auto& t: temps)			//printing out the data stored in the vector
		ofs << t.hour << " " << t.temp << endl;
	
	return 0;
} catch (exception& e) 
{
	cerr << e.what() << endl;
	return 1;
}