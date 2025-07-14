#include<iostream>

using namespace std;

int main()
{
    // Creating Square Matrix
    int matrix_1[2][4] ;
    int matrix_2[4][3] ;
    int matrix_3[2][3] ;

    // Inputting Values From User
    cout << endl ;
    //Matrix 1:
    cout << "Input Matrix 1 values: " << endl ;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> matrix_1[i][j] ;
        }
    }
    //Matrix 2:
    cout << "Input Matrix 2 values: " << endl ;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix_2[i][j] ;
        }
    }

    // Displaying Matrix
    cout << endl ;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix_1[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix_2[i][j] << " " ;
        }
        cout << endl ;
    }
     
    
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                matrix_3[i][j] = 0 ;
            }
        }
    
    cout << endl ;
    cout << "Matrix 3 is:  " << endl ;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                matrix_3[i][j] = matrix_3[i][j] + matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    cout << endl ;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix_3[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0;
}