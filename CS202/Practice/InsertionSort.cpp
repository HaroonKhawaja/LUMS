#include<iostream>

using namespace std;

float* InsertionSort(float* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    bool quit = false;
    float IS_array[100];
    int size = 0;
    int index = 0;
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
    InsertionSort(IS_array, size);
    for (int i = 0; i < size; i++)
    {
        cout << IS_array[i] << " ";
    }
    cout << endl;
    return 0;
}