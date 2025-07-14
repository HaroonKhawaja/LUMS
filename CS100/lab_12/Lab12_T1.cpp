#include<iostream>

using namespace std;

int main()
{
    int size , value ;
    int i ;
    int j ;
    int k = 0 ;
    int diag_sum1 = 0 , diag_sum2 = 0 ;
    int non_diag_sum = 0 ;
    int matrix_sum = 0 ;
    int product_row = 1 ;
    int product_column = 1 ;

    // Creating Square Matrix
    cout << "Create square matrix of size: " ;
    cin >> size ;
    int square_matrix[size][size] ;

    // Inputting Values From User
    cout << endl ;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            
            cout << "element at position: matrix[" << i << "][" << j << "] is: " ;
            cin >> square_matrix[i][j] ;
            matrix_sum = matrix_sum + square_matrix[i][j] ;
        }
    }

    // Displaying Matrix
    cout << endl ;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            cout << square_matrix[i][j] << " " ;
        }
        cout << endl ;
    }

    // Diagonal Sums
    cout << endl ;
    for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (i == j)
                {
                    diag_sum1 = diag_sum1 + square_matrix[i][j] ;
                }
            }
        }
    for (i = size - 1; i >= 0; i--)
    {

        diag_sum2 = diag_sum2 + square_matrix[i][k] ;
        k++ ;
    }
        cout << "Sum of the diagonal entries of the matrix is :" << diag_sum1 + diag_sum2 << endl ;
    
    // Non-Diagonal Sums
    cout << endl 
    int total_diag_sum = diag_sum1 + diag_sum2 ;
    non_diag_sum = matrix_sum - total_diag_sum ;

    cout << "Sum of the non-diagonal entries is :" << non_diag_sum << endl ;

    // Row Product
    cout << endl ;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
           product_row = product_row * square_matrix[i][j] ;
        }
        cout << "Product of Row " << i << " is: " << 1 * product_row << endl ;
        product_row  = 1 ;
    } 
    // Column Product
    cout << endl ;
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < size; i++)
        {
           product_column = product_column * square_matrix[i][j] ;
        }
        cout << "Product of Column " << j << " is: " << product_column << endl ;
        product_column = 1 ;
    }



    // Squaring matrix
    cout << endl ;
    cout << "The squared matrix is: " << endl ;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            square_matrix[i][j] = square_matrix[i][j] * square_matrix[i][j] ;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            cout << square_matrix[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0;
}