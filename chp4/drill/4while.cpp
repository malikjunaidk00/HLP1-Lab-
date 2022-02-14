//drill no.4
#include "./std_lib_facilities.h"
int main()
{
   
    long double x,y;
    cout<<"plz input two integers:";
    while (cin >> x >> y)
    {
        
        cout << "\n\n the number you entered are x:"<<x<<" and y:"<<y<<"\n\n";

        if(x<y)         cout<<"smaller value is:"<<x<<"\nLarger value is:"<<y <<endl;
        else if(y>x)    cout<<"smaller value is:"<<y<<"\nLarger value is:"<<x << endl;
        //drill no.5
        else
         if(abs(x-y)<0.01)  cout << "both numbers are equal i.e "<<x <<"="<<y      <<endl;          //drill no.3
        
        cout<<"\nplz input two decimals:";

    }
    return 0;
    
}
