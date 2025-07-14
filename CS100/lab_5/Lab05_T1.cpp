#include<iostream>

using namespace std;

int main()
{
    int roll_num_1 = 24100241 ;
    int roll_num_2 = 24100214 ;
    int roll_num_3 = 21400241 ;
    int roll_num_4 = 21400214 ;

    int target = 24100241;

    if ( roll_num_2 == target )
        {
        cout << "DO NOT ALLOW " << target << " TO ENTER" ;
        }
    if ( roll_num_3 == target )
        {
        cout << "DO NOT ALLOW " << target << " TO ENTER" ;    
        }
    if ( roll_num_4 == target )
        {
        cout << "DO NOT ALLOW " << target << " TO ENTER" ;    
        }
    if ( roll_num_1 == target )
        {
        cout << "DO NOT ALLOW " << target << " TO ENTER" ;    
        }

    return 0 ;
}