#include "./std_lib_facilities.h"
int main()
{
    double x,max_so_far=0,min_so_far=0;
    cout << "Enter decimals:";
    cin>>x;
    max_so_far= x;
    min_so_far = x;
    if(min_so_far<x) cout <<"\n\nThe smallest number so far is:" << min_so_far <<endl;
        else {
            min_so_far=x;
            cout << "\n\nThe smallest number so far is:" << min_so_far << endl;
        }
        if (max_so_far>x) cout << "The largest number so far is:"<< max_so_far<< "\n\n\n";
        else{
            max_so_far=x;
            cout << "The largest number so far is:"<< max_so_far << "\n\n\n";
        }
        cout << "Enter decimals:";
        
    while(cin>>x)
    {
        if(min_so_far<x) cout <<"\n\nThe smallest number so far is:" << min_so_far <<endl;
        else {
            min_so_far=x;
            cout << "\n\nThe smallest number so far is:" << min_so_far << endl;
        }
        if (max_so_far>x) cout << "The largest number so far is:"<< max_so_far<< "\n\n\n";
        else{
            max_so_far=x;
            cout << "The largest number so far is:"<< max_so_far << "\n\n\n";
        }
        cout << "Enter decimals:";
    }
}