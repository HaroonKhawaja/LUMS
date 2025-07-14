#include <iostream>

using namespace std;

int main()
{
    // Prices Per Liter
    double petrol_prices = 123.300 ; 
    double diesel_prices = 115.030 ;
    double gasoline_prices = 118.300 ;
    
    // Liters Purchases
    int petrol_quantity = 3 ;
    int diesel_quantity = 4 ;
    int gasoline_quantity = 2 ;

    // Total Price Before Tax
    double total_petrol_price =  petrol_prices * petrol_quantity ;
    double total_diesel_price =  diesel_prices * diesel_quantity ;
    double total_gasoline_price =  gasoline_prices * gasoline_quantity ;

    // Total Price Without Tax
    double total_price = total_petrol_price + total_gasoline_price + total_diesel_price ;

    // Taxed Amount
    double tax_percentage = 0.16 ;
    double taxed_petrol_price = total_petrol_price * tax_percentage ;
    double taxed_diesel_price = total_diesel_price * tax_percentage ;
    double taxed_gasoline_price = total_gasoline_price * tax_percentage ;

    // Final Cost inluding Tax
    double final_petrol_price = total_petrol_price + taxed_petrol_price ;
    double final_diesel_price = total_diesel_price + taxed_diesel_price ;
    double final_gasoline_price = total_gasoline_price + taxed_gasoline_price ;
   
    // Total Bill
   double bill = final_diesel_price + final_gasoline_price + final_petrol_price ;

    // Total Tax Amount
   double total_tax = taxed_petrol_price + taxed_diesel_price + taxed_gasoline_price ;

    cout << "Task 1 \n" << endl ;

    cout << "Quantity of Petrol : " << petrol_quantity << " Liters" << endl;
    cout << "Quantity of Diesel : " << diesel_quantity << " Liters" << endl;
    cout << "Quantity of Gasoline : " << gasoline_quantity << " Liters\n" << endl;

    cout << "Dear Lalit you receipt is:\n" << endl;
    cout << "petrol @123.3 Rs/Litre is: " << total_petrol_price << endl ;
    cout << "diesle @115.03 Rs/Litre is: " << total_diesel_price << endl ;
    cout << "gasoline @118.3 Rs/Litre is: " << total_gasoline_price << endl ;

    cout << "\nThe total cost tax is " << total_price << endl ;
    cout << "GST @16 \% is: " << total_tax << endl ;

    cout << "\nThe toal cost after tax is " << bill << endl ;

    cout << "\nTask 2\n" << endl ;

    double m1 = -2 ;
    double c1 = 1 ;
    double m2 = 0.6 ;
    double c2 = -8 ;
    
    double x = ( c2 - c1 ) / ( m1 - m2 ) ;

    double y = ( -2 * x ) + 1 ;

    cout << "(" << x << "," << y << ")" ;
    return 0;
}
