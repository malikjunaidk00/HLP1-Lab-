//drill no.7
#include "./std_lib_facilities.h"
int main()
{
    double given_length;
    char unit;
    double cm_per_meters=100;
    double cm_per_ins=2.54;
    double in_per_ft=12;
    cout << "Enter the lenth followed by unit as 'i' for inches\n'c' for centimetres\n'f' for feet\n'm' for metres\nLength:";
    cin>> given_length>>unit;
    if(unit=='i')
    {
        cout << "\nLength in inches is:"<< given_length<<"in";
        cout << "\nLength in feet is: " << given_length/12 << "ft";
        cout << "\nLength in centimetres is: "<< given_length*2.54 << "cm";
        cout << "\nLength in metres is: "<<(given_length*2.54)/100 << "m";

    }
    else if (unit=='f')
    {
        cout << "\nLength in inches is:"<< given_length*12<<"in";
        cout << "\nLength in feet is: " << given_length << "ft";
        cout << "\nLength in centimetres is: "<< given_length*12*2.54 << "cm";
        cout << "\nLength in metres is: "<<(given_length*12*2.54)/100 << "m";

    }
    else if (unit=='c')
    {
        cout << "\nLength in inches is:"<< given_length/(2.54)<<"in";
        cout << "\nLength in feet is: " << given_length/(12*2.54) << "ft";
        cout << "\nLength in centimetres is: "<< given_length << "cm";
        cout << "\nLength in metres is: "<<(given_length)/100 << "m";

    }
    else if (unit=='m')
    {
        cout << "\nLength in inches is:"<< given_length*100*2.54<<"in";
        cout << "\nLength in feet is: " << (given_length*100)/(12*2.54) << "ft";
        cout << "\nLength in centimetres is: "<< given_length*100 << "cm";
        cout << "\nLength in metres is: "<<given_length << "m";

    }
    //drill no.8
    else cout << "\nunit conversion is not possible as unit entered is not valid"<<endl;
    return 0;
}