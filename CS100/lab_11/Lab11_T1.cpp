#include<iostream>

using namespace std;

int main()
{
    int rows , cols ;
    int find ;
    int occurence = 0;
    int less_than = 0 ;
    int greater_than = 0 ;

    cout << endl ;
    cout << "Please enter matrix rows: " ;
    cin >> rows ;

    cout << "Please enter matric cols: " ;
    cin >> cols ;

    int matrix[rows][cols] ;

    // Inputting Matrix Values
    cout << endl ;
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
    cout << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << matrix [i][j] << " " ;
        }
        cout << endl ;
    }
    // Total Occurences
    cout << endl ;
    cout << "Please enter the number to look for: " ;
    cin >> find;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == find)
            {
                occurence = occurence + 1 ;
            }
        }
    }
    cout << "Element " << find << " was repeated " << occurence << " times." << endl ;

    // Less & Greater
    cout << endl ;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] < find)
            {
                less_than = less_than + 1 ;
            }
            else if (matrix[i][j] > find)
            {
                greater_than = greater_than + 1 ;
            }
        }
    }
    cout << "Element " << find << " has " << less_than << " elements less than it and " << greater_than << " elements greater than it." << endl ;
    return 0;
}