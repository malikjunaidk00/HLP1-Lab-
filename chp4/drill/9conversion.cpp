#include "./std_lib_facilities.h"
void conversion(double,char);
double sum(double,char);
void num_decider(double);
int main()
{   
    int count=0;
    double sum_till_now=0;

    double given_length;
    char unit;
    double cm_per_meters=100;
    double cm_per_ins=2.54;
    double in_per_ft=12;
    cout << "Enter the lenth followed by unit as 'i' for inches\n'c' for centimetres\n'f' for feet\n'm' for metres\nLength:";
    while (cin>> given_length>>unit)
    {
        conversion(given_length,unit);

        //sum of the lengths entered till now in metres
        sum_till_now+=sum(given_length,unit);
        cout <<"\nsum till now is:"<< sum_till_now <<"m";

        //total numbers entered till now
        count=count+1;
        cout <<"\nValues entered till now are:" <<count;

        //smallest and largest numbers till now
        num_decider(given_length);

        cout << "\n\n\nEnter the lenth followed by unit as 'i' for inches\n'c' for centimetres\n'f' for feet\n'm' for metres\nLength:";

    }
    


    return 0;
}
void conversion(double x,char y)
{
    double given_length=x;
    char unit=y;
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
}

double sum(double x,char y)
{
    
    double given_length=x;
    char unit=y;
    if(unit=='i')
    {
      return (given_length*2.54)/100 ;

    }
    else if (unit=='f')
    {
       return (given_length*12*2.54)/100;

    }
    else if (unit=='c')
    {
       return (given_length)/100 ;

    }
    else if (unit=='m')
    {
       return given_length;

    }
    else return 0;
}
void num_decider(double x)
{
    double max_so_far,min_so_far;
 
    if(x>min_so_far) cout <<"\nThe smallest number so far is:" << min_so_far <<endl;
     else
      {
            min_so_far=x;
            cout << "\nThe smallest number so far is:" << min_so_far << endl;
        }

    if (max_so_far>x) cout << "The largest number so far is:"<< max_so_far<< "\\n";
        else{
            max_so_far=x;
            cout << "The largest number so far is:"<< max_so_far << "\n";
        }
 
}