#include <iostream>

using namespace std;

int main ()
{
    cout << "Please select your desired operation by enterin a number from 1 to 5: " << endl ;
    cout << "\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. End Program" << endl ;

    int i ;
    cout << " Your Input (1 - 5): " ;
    cin >> i ;
        if (i == 1)
        {
            int x;
            cout << "Enter number to add (or enter 0 to stop): " ;
            cin >> x ;
            int sum = 0 ;
            while (x != 0)
            {
                    cout << "Enter number to add (or enter 0 to stop): " ;
                    cin >> x ;
                    sum = sum + x ;
            }
            cout << "The sum is " << sum ;
        }
        else if (i == 2)
        {
            int y;
            cout << "Enter number to subtract (or enter 0 to stop): " ;
            cin >> y ;
            int subtraction = 0 ;
            while (y != 0)
            {
                    cout << "Enter number to subtract (or enter 0 to stop): " ;
                    cin >> y ;
                    subtraction = subtraction - y ;
            }
            cout << "The difference is " << subtraction ;
        }



    return 0;
}