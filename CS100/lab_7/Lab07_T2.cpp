#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a positive integer greater than 0: " ;
    int n ;
    cin >> n ;

    if (n <= 0)
    {
        cout << "Invalid input. Number must be greater than 0." ;
    }
    else if (n == 1)
    {
        cout << " 1 is not a prime number" ;
    }
    else if (cin.fail()) return 0;

    else
    {   
        int i;
        bool num;
        for ( i = 1; i <= n - 1; i++ )
        {
            if(n % i == 0)
            {
                num = 1 ;
            }

        }
        if (num = 1)
        {
            cout << "Number is prime" ;
        }
        else
        {
            cout << "Numer is not a prime" ;
        }
    }
    return 0;
}