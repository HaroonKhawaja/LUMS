#include <iostream>
#include <iomanip>
using namespace std;



// creates the functionality of a vector using dynamic arrays
// you are allowed to make as many helper functions as you need to
class CreateVector
{
    public:

    int array_size;
    int* array = new int[20];

    void print();
    // TO-DO Function
    // constructor
    CreateVector()
    {
        // set array size to 0
        array_size = 0;
        int* array = new int[array_size];
    }


    // TO-DO Function
    // operator overloading, [] will be used to index the array
    int operator [] (int i)
    {
        return array[i] ;
    }


    // TO-DO Function
    void push(int a)
    {
        // add element to the end of the array
        // adjust size of the array
        int* stored_array = new int[array_size]; // creating an array to store original array

        for(int i = 0; i < array_size; i++) // for-loop to store each index of original array to stored array
            stored_array[i] = array[i];

        array_size += 1; // increasing the array size
                
        array = new int[array_size]; // increasing the size of the original array
        for(int i = 0; i < array_size - 1; i++) // copying back the stored array into original array
            array[i] = stored_array[i];

        array[array_size - 1] = a; // adding the new element to updated original array   
    }


    // TO-DO Function
    int pop()
    {
        // remove last element from the array and return it
        // adjust size of the array
        // if this function is called on an empty array, do not remove anything and simply return -1
        if(array_size == 0)
            return -1;
        else
        {
            int last_element = array[array_size - 1];

            array_size -= 1; // decreasing the array size

            for(int i = 0; i < array_size; i++) //for-loop to copy all except last element into original array
            {
                array[i] = array[i];
            }
            return last_element; // returning popped element
        }
    }


    // TO-DO Function
    int vectorLength()
    {
        // return length of the array
        int length = 0;
        for (int i = 0; i < array_size; i++)
            length += 1;
        return length;
    }


    // TO-DO Function
    void removeFromIndex(int index)
    {
        // remove the element at a given index
        // adjust size of the array
        for(int i = 0; i < array_size; i++)
        {
            if(i == index)
            {
                array_size -= 1;
                for(int j = i; j < array_size; j++)
                {
                    array[j] = array[j+1];
                }
            }
        }
    }


    // TO-DO Function
    void removeValue(int val)
    {
        // remove the first occurence of the element from the array that has the given value
        // adjust size of the array
        //int* stored_array = new int[array_size];
        for(int i = 0; i < array_size; i++)
        {
            if(array[i] == val)
            {
                array_size -= 1;
                for (int j = i; j < array_size; j++)
                {
                    array[j] = array[j+1];
                }
            }
        }
    }


    // TO-DO Function
    // destructor
    ~CreateVector()
    {
        // delete array;
    }
};

void CreateVector::print()
{
    for(int i = 0; i < array_size; i++)
        cout << array[i] << " ";
    cout << endl ;
}


// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_1.cpp

// int main()
// {
//     CreateVector v;
//     int input ;
//     bool exit = false;
//     do
//     {
//         cout << "\n1. Push\n2. Pop\n3. Vector Length\n4. Remove from Index\n5. Remove Value\n6. Exit" << endl;
//         cout << "Input: ";
//         cin >> input ;

//         switch (input)
//         {
//             case 1: // push
//                 int element;
//                 cout << "\nPush element: ";
//                 cin >> element;
//                 v.push(element);
//                 cout << "Updated vector:" << endl;
//                 v.print();
//                 break;

//             case 2: // pop
//                 cout << "\nPopped last element: " << v.pop() << endl; 
//                 cout << "Updated vector:" << endl;
//                 v.print();
//                 break; 

//             case 3:
//                 cout << "\nLength of the vector is: " << v.vectorLength() << endl ;
//                 break;

//             case 4:
//                 int index;
//                 cout << "\nRemove from index: ";
//                 cin >> index;
//                 v.removeFromIndex(index);
//                 v.print();
//                 break;

//             case 5:
//                 int value;
//                 cout << "\nRemove value: ";
//                 cin >> value;
//                 v.removeValue(value);
//                 v.print();
//                 break;

//             case 6:
//                 exit = true;
//                 break;

//             default:
//                 break;
//         }
//     } while (exit == 0);
// }