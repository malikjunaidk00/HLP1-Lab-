#include "std_lib_facilities.h"

int main()
{
	
	int a = 10, b = 20;
	int max = 0;
	/*
	if (a > b)
		max = a;
	else
		max = b;
	cout << max << endl;
	*/
	//ternary operator
	max = a > b ? a : b;
	cout << max << endl;
	
	return 0;

}
