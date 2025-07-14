#include<iostream>

using namespace std;

float* SelectionSort(float* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallPos = i;
        float smallest = arr[smallPos];
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j] < smallest)
            {
                smallPos = j;
                smallest = arr[smallPos];
            }
        }
        arr[smallPos] = arr[i];
        arr[i] = smallest;
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
    SelectionSort(IS_array, size);
    for (int i = 0; i < size; i++)
    {
        cout << IS_array[i] << " ";
    }
    cout << endl;
    return 0;
}