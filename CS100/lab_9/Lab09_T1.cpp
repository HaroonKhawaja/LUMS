#include<iostream>

using namespace std;

void reverseFunction(string str)
{
    string x ;
    int n = str.length() ;
    for(int i = n -1 ; i >= 0; i--)
    {
        cout << str[i] ;
    }
}

int main()
{
    cout << "Input sentence to reverse it :" ;
    string sentence ;
    getline(cin , sentence) ;
    reverseFunction(sentence) ;

    return 0 ;
}