#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{

    cout << "Does the animal live in the sea?\nEnter 1 if yes, enter 0 if no: " ;
    bool lives_in_sea ;
    cin >> lives_in_sea ;

    if (lives_in_sea == 1) // In Sea
    {
        cout << "Is it a mammal?\nEnter 1 if yes, enter 0 if no: " ;
        bool is_mammal ;
        cin >> is_mammal ;
    
        if (is_mammal == 1) // Is Mammal
        {
            cout << "The animal is a Whale or Dolphin" ;
        }
        else if (is_mammal == 0)
        {
            cout << "Is it cute?\nEnter 1 if yes, enter 0 if no: " ;
            bool is_it_cute ;
            cin >> is_it_cute ;
            
            if (is_it_cute == 1) // Is Cute
            {
                cout << "The animal is a Dolphin" ;
            }
            else if (is_it_cute == 0) // Not Cute
            {
                cout << "The animal is a Shark" ;
            }
        }
    }
    else if (lives_in_sea == 0) // Not in Sea
    {
        cout << "Does it have wings?\nEnter 1 if yes, enter 0 if no: " ;
        bool has_wings ;
        cin >> has_wings;

        if (has_wings == 1) // Has wings
        {
            cout << "Can it fly?\nEnter 1 if yes, enter 0 if no: " ;
            bool flies ;
            cin >> flies ;

            if (flies == 1) // Flies
            {
                cout << "The animal is a Parrot" ;
            }
            else if (flies == 0) //Doesnt Fly
            {
                cout << "The animal is a Chicken" ;
            }
        }
        else if (has_wings == 0) // No Wings
        {
            cout << "The animal is a Lion" ;
        }
    }

    return 0 ;
}