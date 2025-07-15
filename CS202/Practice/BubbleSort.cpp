#include<iostream>

using namespace std;

float* BubbleSort(float* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            float temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
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
    BubbleSort(IS_array, size);
    for (int i = 0; i < size; i++)
    {
        cout << IS_array[i] << " ";
    }
    cout << endl;
    return 0;
}