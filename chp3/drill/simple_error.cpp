//drill no.5
#include "./std_lib_facilities.h"
int main()
{
    int age;
    cout << "Enter your age plzzz:";
    cin >> age;
    if (age<=0 || age>=110)
    simple_error("you're kidding!");
    else cout <<"\nI hear you just had a birthday and you are "<< age << " years old.\n";

    //no.6
    if(age<12 && age>0)
    cout << "\nNext year you will be "<<age+1 << " years old.\n";
    else if (age==17) 
    cout << "\nNext year you will be able to vote\n";
    else if (age>=70)
    cout << "\nI hope you are enjoying retirement!\n";

    //no.7
    cout << "\n\nYours Sincerely,\nMALIK JUNAID! \n\n";
    return 0;
}