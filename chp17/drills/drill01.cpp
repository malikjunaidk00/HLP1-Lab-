#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a)			//Write a function print_array10(ostream& os, int* a) 
												//that prints out the values of a (assumed to have ten elements) to os.
{		
    for (int i=0; i<10; i++) os << a[i] << ",";
    cout << endl;
}


//Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os. --drill07
void print_array(ostream& os, int* a, int n){
    for (int i=0; i<n; i++) os << a[i] << ",";
    cout << endl;
}

void vecPrint(ostream& os,vector<int> vec){
    for (auto e:vec) os << e << ",";
    cout << endl;
}


int main(){

    int* arr10 = new int[10];					//Allocate an array of ten ints on the free store using new.		--drill01
    for (int i=0; i<10; i++) arr10[i] = 100+i;	//Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.		--drill05
    print_array10(cout, arr10);					//Print the values of the ten ints to cout.			--drill02
    delete[] arr10;								//Deallocate the array (using delete[]).			--drill03

    int* arr11 = new int[11];					//Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.		--drill06
    for (int i=0; i<11; i++) arr11[i] = 100+i;
    print_array(cout, arr11, 11);
    delete[] arr11;

    int* arr20 = new int[20];					//Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.		--drill08
    for (int i=0; i<20; i++) arr20[i] = 100+i;
    print_array(cout, arr20, 20);
    delete[] arr20;

//Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array(). 	--drill10
    vector<int> vec10;
    for (int i=0; i<10; i++) vec10.push_back(100+i);
    vecPrint(cout,vec10);

    vector<int> vec11;
    for (int i=0; i<11; i++) vec11.push_back(100+i);
    vecPrint(cout,vec11);

    vector<int> vec20;
    for (int i=0; i<20; i++) vec20.push_back(100+i);
    vecPrint(cout,vec20);

/*part 2*/

//Allocate an int, initialize it to 7, and assign its address to a variable p1.			--drill01
    int seven = 7;	
    int* p1 = &seven;
    cout << "P1 Adress = " << p1 << " and the value = " << *p1 << endl;  //Print out the value of p1 and of the int it points to.		--drill02
   
//Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.			--drill03
    int arr7[7];
    for (int i=0; i<7; i++) arr7[i] = pow(2,i);
    int* p2 = arr7;
    cout << "P2 Adress = " << p2 << " and the value = " ;		//Print out the value of p2 and of the array it points to.			--drill04
    print_array(cout,p2,7);


//Declare an int* called p3 and initialize it with p2.		--drill05	
    int* p3 = p2;
    p2 = p1;					//Assign p1 to p2.			--drill06
    p2 = p3;					//Assign p3 to p2.			--drill07
    cout << "P1 Adress = " << p1 << " and the value = " << *p1 << endl;		//Print out the values of p1 and p2 and of what they point to.		--drill08
    cout << "P2 Adress = " << p2 << " and the value = " << *p2 << endl;

    p1 = nullptr; p2=nullptr; p3=nullptr; 									//Deallocate all the memory you allocated from the free store.		--drill09
//  
    int arr10_2[10];														//Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.		--drill10
    for (int i=0; i<10; i++) arr10_2[i] = pow(2,i);
    p1 = arr10_2;

    int arr10_3[10];    													//Allocate an array of ten ints, and assign its address to a variable p2.		--drill11
    p2 = arr10_3;

    for (int i=0; i<10; i++) p2[i] = p1[i];									//Copy the values from the array pointed to by p1 into the array pointed to by p2.		--drill12


//Repeat 10–12 using a vector rather than an array.
    vector<int> vec10_2;
    for (int i=0; i<10; i++) vec10_2.push_back(pow(2,i));
    vector<int>* P1 = &vec10_2;

    vector<int> vec10_3;
    vector<int>* P2 = &vec10_3;
    for (int i=0; i<P1->size(); i++) P2->push_back((*P1)[i]);

    cout << "\nP2 output:\n";
    for (int i=0; i<P2->size(); i++) cout << (*P2)[i] << " ";

    return 0;
}