#include <iostream>

using namespace std;

int main()
{
    int x;
    int i;
    int sum = 0;
    int product = 1;
    int avg;

    for (i = 1; i <= 5; i++)
    {
        cout << "Enter Number: " ;
        cin >> x ;
        sum = sum + x ;
        product = product * x ; 
        avg = sum / i ;
    }
    

    cout << "Sum: " << sum << endl ;
    cout << "Product: "  << product << endl ;
    cout << "Average : " << avg << endl ;

    return 0;
}