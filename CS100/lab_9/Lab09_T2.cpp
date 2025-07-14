#include<iostream>

using namespace std;
int  openAccount()
{
    int age , opening_amount;
    string first_name , profession ;
    cout << "Please enter your first name:" << endl ;
    cin >> first_name ;
    cout << "Please enter your age:" << endl ;
    cin >> age ;
    cout << "Please enter your Profession" << endl ;
    cin >> profession ;
    cout << "Please enter opening amount" << endl ;
    cin >> opening_amount ;
    
    cout << "Hello " << "Haroon" << ", your account has been opened. Your opening balance is: " << opening_amount ;
    cout << endl ;
    return opening_amount ;
}

int depositMoney()
{
    int deposit_amount ;
    cout << "Please enter the deposit amount:" << endl ;
    cin >> deposit_amount ;
    cout << endl ;

    return deposit_amount ;
}

int withdrawMoney()
{
    int withdraw_amount ;
    cout << "Please enter the amount you want to withdraw:" << endl;
    cin >> withdraw_amount ;
    return withdraw_amount ;
}

int main()
{
    int input ;

    cout << "Welcome to The Bank. Please select one of the following options: :" << endl ;
    do
    {
        cout << endl ;
        cout << "Enter 1 to Open Account" << endl ;
        cout << "Enter 2 to Withdraw Money" << endl ;
        cout << "Enter 3 to Deposit Money" << endl;
        cout << "Enter 0 to Exit" << endl ;

        cin >> input ;
        int opening_amount = 0 ;
        if (input == 1)
        {
            opening_amount = openAccount();
        }
        else if (input == 2)
        {
            int withdraw_amount = withdrawMoney() ;
            if (opening_amount > 0)
            {
                cout << "withdrawal successful. Your updated amount is " << opening_amount - withdraw_amount ;
            }
            else
            {
                cout << "insufficient balance." ;
            }
        }
        else if (input == 3)
        {
            int deposit_amount = depositMoney() ;
            cout << "deposit successful. Your Updated amount is: " << opening_amount + deposit_amount ;
            cout << endl ;
        }
    } while (input != 0) ;

    cout << "Thank you for banking with us" ;


    return 0;
}