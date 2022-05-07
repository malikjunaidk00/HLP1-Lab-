#include "std_lib_facilities.h"

int main()
try {
	string name;
	int age;
	string first_name, last_name;
	
	getline(cin, name);

	stringstream ss {name}; 		//name of string or file you want to split
	
	ss >> first_name >> last_name >> age;

	cout << first_name << ' ' << last_name << " " << age << endl;


	//cout << name << endl;


	return 0;
}

catch (exception& e)
{
	cerr << e.what() << endl;
	return 1;
}