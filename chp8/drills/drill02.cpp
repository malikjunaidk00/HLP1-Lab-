/* Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const int&, const int&). Each should
have the body
{ int temp; temp = a, a=b; b=temp; }
where a and b are the names of the arguments.
Try calling each swap like this
Click here to view code image
int x = 7;
int y =9;
swap_?(x,y); // replace ? by v, r, or cr
swap_?(7,9);
const int cx = 7;
const int cy = 9;
swap_?(cx,cy);
swap_?(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_?(dx,dy);
swap_?(7.7,9.9);
Which functions and calls compiled, and why? After each swap that compiled, print the value of the arguments after the
call to see if they were actually swapped. If you are surprised by a result, consult §8.6.
*/

#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "value of a by function = "<< a << "  value of b by function = " << b << endl;      //adding this line to understand if the function swap is working both inside & outside
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "value of a by function = "<< a << "  value of b by function = " << b << endl;      //adding this line to understand if the function swap is working both inside & outside
}
/*
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;              //gives the error  as assignment of read only reference 'a'  the reason is cz const integers have fixed values and cannot be swapped
    b = temp;           //gives the error  as assignment of read only reference 'b'  the reason is cz const integers have fixed values and cannot be swapped
    cout << "value of x by function = "<< a << "  value of y by function = " << b << endl;      //adding this line to understand if the function swap is working both inside & outside
}
*/

int main()
{

//part1
    //checking swap_v
    int x = 7;
    int y =9;
    swap_v(x,y);                    // replace ? by v, r, or cr
    cout << "value of x by main = "<< x << "  value of y by main = " << y << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_v(7,9);
    //compiled fully for swap_v

    cout << endl;
    //checking for swap_r
     x = 7;
     y =9;
    swap_r(x,y);                    // replace ? by v, r, or cr
    cout << "value of x by main = "<< x << "  value of y by main = " << y << endl;      //adding this line to understand if the function swap is working both inside & outside
//    swap_r(7,9);                    // this statement will give error as swap_r is reference address not for the values of a & b
                                    //gave error "cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'"
    
    //compiled for swap_r(x,y) but for swap_r(7,9) gave error mentioned over

/*    //checking for swap_cr
     x = 7;
     y =9;
    swap_cr(x,y);                    // replace ? by v, r, or cr
    cout << "value of x by main = "<< x << "  value of y by main = " << y << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_cr(7,9);                   //
    // couldn't compiled cz of     swapping of read only values
*/

    cout << "\n\n\n";
//part 2
    //checking for swap_v
    const int cx = 7;
    const int cy = 9;
    swap_v(cx,cy);
    cout << "value of cx by main = "<< cx << "  value of cy by main = " << cy << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_v(7.7,9.9);
    //compiled fully

    //checking for swap_r
//     cx = 7;          
//     cy = 9;
//     swap_r(cx,cy);                          // binding reference of type 'int&' to 'const int' discards qualifiers
//     cout << "value of cx by main = "<< cx << "  value of cy by main = " << cy << endl;      //adding this line to understand if the function swap is working both inside & outside
//     swap_r(7.7,9.9);                        // cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // couldn't compiled  --error are mentioned after each swap
/*
    //checking for swap_cr
    cx = 7;
    cy = 9;
    swap_cr(cx,cy);
    cout << "value of cx by main = "<< cx << "  value of cy by main = " << cy << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_cr(7.7,9.9);
    //couldn't compile cz of swapping of read only values
*/

    cout << "\n\n\n";
//part 3
    //checking for swap_v
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);                  // compiled but it gave only integer part not decimal part
    cout << "value of dx by main = "<< dx << "  value of dy by main = " << dy << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_v(7.7,9.9);
    //compiled  but for integral part only
/*
    //checking for swap_r
     dx = 7.7;
     dy = 9.9;
    swap_r(dx,dy);                      //cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    cout << "value of dx by main = "<< dx << "  value of dy by main = " << dy << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_r(7.7,9.9);                    //cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //couldn't compile errors are mentioned above after each function call
    //checking for swap_cr
     dx = 7.7;
     dy = 9.9;
    swap_cr(dx,dy);
    cout << "value of dx by main = "<< dx << "  value of dy by main = " << dy << endl;      //adding this line to understand if the function swap is working both inside & outside
    swap_cr(7.7,9.9);
    //couldn't compile errors are the same read only constant values swapping
*/
    return 0;
}