#include "std_lib_facilities.h"

int fac(int n){
    int factorial = 1;
    for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
    return factorial;
}

int ga[10]={1,2,4,8,16,32,64,128,256,512};              //1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.

void f(int* arr, int n){                                //2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
    int la[10];                                         //a. Define a local int array la of ten ints.
    for (int i=0; i<10; i++) la[i] = ga[i];             //b. Copy the values from ga into la

    cout << "\nElements of la are:\n";                  //c. Print out the elements of la.
    for (int i=0; i<10; i++) cout << la[i] << endl;

    int* p = new int[n];                                //d. Define a pointer p to int and initialize it with an array allocated on the free store with the same number of
                                                        //   elements as the argument array.
    for (int* i=p; i<p+n; i++) *i = arr[i-p];           //e. Copy the values from the argument array into the free-store array.
    cout << "\nElements of free store array are:\n";    //f. Print out the elements of the free-store array.
    for (int* i=p; i<p+n; i++) cout << *i << endl;
    delete[] p;                                         //g. Deallocate the free-store array.
}

int main(){
    cout << "<-----------f(ga,10)----------->";         //a. Call f() with ga as its argument.
    f(ga,10);

    int aa[10];                                         //b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1,etc.).
    for (int i=0; i<10; i++) aa[i] = fac(i+1);

    cout << "<-----------f(aa,10)----------->";         //c. Call f() with aa as its argument.
    f(aa,10);
        
    return 0;
}