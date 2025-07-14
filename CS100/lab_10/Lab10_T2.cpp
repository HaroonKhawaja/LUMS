#include <iostream>

using namespace std;

void addOne(int arr[] , int n)
{    
    for (int i = 0; i < n; i++)
    {
        arr[i] += 1 ;
    }
    cout << "Updated array after adding 1: " << endl ;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main()
{
    int my_array[5] ;
    int input ;

    cout << "Give 5 integers for the array" << endl ;
    for (int i = 0; i < 5; i++)
    {
        cin >> input ;
        my_array[i] = input;
    }
    addOne(my_array,5) ;

    return 0;
}