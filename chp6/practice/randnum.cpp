#include "std_lib_facilities.h"

int main()
{
	srand(time(NULL));
	//generate a random number from10-20
	
	int x = rand() % (60 - 20 + 1) + 20;
	cout << x << endl;
	return 0;

}
