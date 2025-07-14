#include <iostream>

using namespace std;

int main ()
{   
    cout << "Enter one characters ASCII code: "  ;     
    int x ;
    cin >> x ;
    cout << char(x) << endl ;
    if (x >= 0)
        while ( x >= 0)  
        {
            cout << "Enter one characters ASCII code: "  ;
            cin >> x ;            
            cout << char(x) << endl ;
        }
    else if (x == -1);

    return 0;
}