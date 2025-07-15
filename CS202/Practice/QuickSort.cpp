#include<iostream>

using namespace std;

float* QuickSort(float* arr, int size, int pivot)
{
    if (size == 0 || size == 1)
    {
        return arr;
    }
    else
    {
        int i = size - 1;
        while (i >= 0 && arr[i] <= pivot)
        {
            /* code */
        }
        
        
    }
    
}

int main()
{
    bool quit = false;
    float IS_array[100];
    int size = 0;
    int index = 0;
    float pivot;
    while (!quit || size == 100)
    {
        float input;
        cout << "Enter input (0 to quit): ";
        cin >> input;
        if (input == 0)
        {
            quit = true;
        }
        else
        {
            size++;
            IS_array[index] = input;
            index++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << IS_array[i] << " ";
    }
    cout << endl;
    cout << "Select pivot element: " ;
    cin >> pivot;
    QuickSort(IS_array, size, pivot);
    for (int i = 0; i < size; i++)
    {
        cout << IS_array[i] << " ";
    }
    cout << endl;
    return 0;
}