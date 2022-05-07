#include "std_lib_facilities.h"

int fac(int n){
    int factorial = 1;
    for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
    return factorial;
}

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};        //1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.

void f(vector<int> vec){                                //2. Define a function f() taking a vector<int> argument.
    vector<int> lv;                                     //a. Define a local vector<int> lv with the same number of elements as the argument vector.
    lv.reserve(vec.size());
    for (auto e:gv) lv.push_back(e);                    //b. Copy the values from gv into lv

    cout << "\nElements of lv are:\n";                  //c. Print out the elements of lv.
    for (auto e:lv) cout << e << endl;

    vector<int> lv2 = vec;                              //d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
    cout << "\nElements of lv2 are:\n";
    for (auto e:lv2) cout << e << endl;                 //e. Print out the elements of lv2.
}

int main(){
    cout << "<-----------f(gv)----------->";
    f(gv);                                              //a. Call f() with gv as its argument.

    vector<int> vv;                                     //    //b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    for (int i=0; i<10; i++) vv.push_back(fac(i+1));
    cout << "<-----------f(vv)----------->";
    f(vv);                                              //c. Call f() with vv as its argument.

    return 0;
}