#include<iostream>

using namespace std;

int main()
{
    int rows = 3 ;
    int cols = 3 ;
    int matrix[rows][cols] ;
    int j = 0 ;
    int sum_upper = 0 ;
    int sum_lower = 0 ;

    cout << "Enter values: " << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "element at position: matrix[" << i << "][" << j << "] is: " ;
            cin >> matrix[i][j] ;
        }
    }
    cout << endl ;
    // Outputting Matrix
    cout << "The input matrix is: " << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << matrix [i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
    // Upper Half
    cout << "Upper half of matrix is: " << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(j = 0 ; j < cols; j++)
        {
            if (i <= j)
            {
                cout << matrix [i][j] ;
                sum_upper = sum_upper + matrix [i][j] ;
            }
            else    
            {
                cout << " " ;
            }
        }
        cout << endl ;
    }
    cout << endl ;
    // Lower Half
    cout << "Upper half of matrix is: " << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(j = 0 ; j < cols; j++)
        {
            if (i >= j)
            {
                cout << matrix [i][j] ;
                sum_lower = sum_lower + matrix [i][j] ;
            }
            else    
            {
                cout << " " ;
            }
        }
        cout << endl ;
    }
    cout << endl ;
    // Sum of Upper & Sum of Lower
    cout << "sum of upper half is: " << sum_upper << endl ;
    cout << endl ;
    cout << "sum of lower half is: " << sum_lower << endl ;
    cout << endl ;
    if (sum_upper > sum_lower)
    {
        cout << "Sum of upper half is greater." ; 
    }
    else if (sum_lower > sum_upper)
    {
        cout << "Sum of lower half is greater." ; 
    }
    else if (sum_upper == sum_lower)
    {
        cout << "Sums are equal." ; 
    }
    return 0 ;
}