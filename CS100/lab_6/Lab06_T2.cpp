#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Input Relative Day Number: " ;
    int weekday_number ;
    cin >> weekday_number ;

    switch (weekday_number)
    {
    case 1 :
        cout << "Monday" ;
        break;
    case 2 :
        cout << "Tuesday" ;
        break ;
    case 3 :
        cout << "Wednesday" ;
        break;
    case 4 :
        cout << "Thursday" ;
        break;
    case 5 :
        cout << "Friday" ;
        break;
    case 6 :
        cout << "Saturday" ;
        break;
    case 7 :
        cout << "Sunday" ;
        break;
    default :
        cout << "Invalid Weekday Number" ;
    }

    return 0 ;
}