#include "./std_lib_facilities.h"
int main()
{   
    //Drill no.1
    string first_name;
    cout <<"enter the name:";
    cin >> first_name;
    cout << "\nHello, " << first_name << endl;
    cout << "Enter the name of the person You want to write to:";                                              // modification
    //no.2
    cin >> first_name;                                                                                         //assigning new value to first_name
    cout << "Dear " << first_name <<",\nHow are you? \nI am fine. \nI miss you.\n";                               //after modification final display
    cout << "\nEnter any name of your friend you are looking for:";
    //no.3
    string friend_name;
    cin >> friend_name;
    cout << "\nHave you seen "<<friend_name<<" lately?" << endl;
    //no.4
    char friend_sex='0';
    cout << "\nEnter an 'm' if the friend is male and an 'f' if the friend is female:";
    cin >> friend_sex;
    if (friend_sex=='m')
    cout << "\nIf you see "<<friend_name <<" ask him to call me.\n";
    else if(friend_sex=='f')
    cout << "\nIf you see "<<friend_name <<" ask her to call me.\n";
    else {
        cout <<"Gender value is not valid.\nPlease enter an 'm' if the fried is male or an 'f' if the friend is female:";
        cin >> friend_sex;
    }
    return 0;
}