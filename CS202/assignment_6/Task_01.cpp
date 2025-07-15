#include <iostream>
#include <string>
using namespace std;


// defines a HeapElement object
// DO NOT CHANGE THE MEMBER VARIABLE SET OR CONSTRUCTOR
// You can, however, do operator overloading
class HeapElement
{
public:
    string name;
    int priority;

    HeapElement()
    {
        name = "";
        priority = -1;
    }

    HeapElement(string _name, int _priority)
    {
        name = _name;
        priority = _priority;
    }
};

/* -----------------------------------------------------------------------------

You can create as many helper functions as you need in the classes.

----------------------------------------------------------------------------- */
class MaxHeap
{
public:
    HeapElement *heap_array;
    int capacity;
    int length;

    // Helper Functions
    void Heapify(int index);
    void HeapSort(int index);
    void perculateDown(int index);

    // TO DO Function
    MaxHeap(int _capacity)
    {
        // parameterized Constructor
        // dynamically allocate an array of HeapElement objects of size capacity
        // set capacity to _capacity and length to 0
        capacity = _capacity;
        heap_array = new HeapElement[capacity];
        length = 0;
    }

    // TO DO Function
    int getParent(int index)
    {
        // return the parent’s index of the given index
        // floor[(index-1)/2]
        int parent_index = (index - 1)/2;
        return parent_index;
    }

    // TO DO Function
    int getLeftChild(int index)
    {
        // return the left child’s index of the given index 
        // 2*index + 1
        int lc_index = ((2 * index) + 1);
        return lc_index;
    }

    // TO DO Function
    int getRightChild(int index)
    {
        // return the left child’s index of the given index
        // 2*index + 2
        int rc_index = ((2 * index) + 2);
        return rc_index;
    }

    // TO DO Function
    bool insertElement(string _name, int _priority)
    {
        // insert a HeapElement with name _name and priority _priority into the Max Heap: return True
        // heapify the Max Heap if necessary
        // if the Max Heap’s capacity has been reached: return False
        if (length == capacity)
        {
            return false;
        }
        // cout << "Inserting: " << _name << " - " << _priority << endl;
        heap_array[length].name = _name;
        heap_array[length].priority = _priority;
        length++;
        int l_nonleaf = length/2 - 1; // non-leaf node
        Heapify(l_nonleaf);
        return true;
        
    }

    // TO DO Function
    HeapElement getMax()
    {
        // return the maximum HeapElement in the Max Heap
        HeapElement max_element = heap_array[0];
        return max_element;
    }

    // TO DO Function
    HeapElement extractMax()
    {
        // remove and return the maximum HeapElement in the Max Heap + decrementing length as well
        // heapify the Max Heap if necessary
        
        HeapElement max_element = heap_array[0];
        HeapSort(0); // deleting max and sorting accordingly
        for (int i = 0; i <= length/2 - 1; i++) // heapifying every node from root to last non-leaf node
        {
            Heapify(i);
        }
        return max_element;
    }

    // TO DO Function
    bool increasePriority(int index, int offset)
    {
        // increase of the HeapElement at index by offset: return True
        // heapify the Max Heap if necessary
        // if the index is out of range: return False
        if (index >= length)
        {
            return false;
        }
        heap_array[index].priority += offset;
        Heapify(index);
        return true;
    }

    // TO DO Function
    bool deleteElement(string _name)
    {
        // remove a HeapElement with name _name into the Max Heap: return True
        // heapify the Max Heap if necessary
        // if the HeapElement doesn't exist: return False
        if (heap_array[0].name == _name)
        {
            HeapSort(0);
        }
        else
        {
            int delete_index = -1;
            for (int i = 0; i < length/2 - 1; i++)
            {
                int lc = getLeftChild(i);
                int rc = getRightChild(i);
                if (lc < length && heap_array[lc].name == _name)
                {
                    delete_index = lc;
                    break;
                }
                else if (rc < length && heap_array[rc].name == _name)
                {
                    delete_index = rc;
                    break;
                }
            }
            if (delete_index == -1)
            {
                return false;
            }
            HeapSort(delete_index);
        }
        for (int i = 0; i <= length/2 - 1; i++) // heapifying every node from root to last non-leaf node
        {
            Heapify(i);
        }
    }

    // TO DO Function
    ~MaxHeap()
    {
        // set the heap_array pointer to NULL and deallocate all HeapElement objects in the Max Heap
        // this will be checked manually
        delete heap_array;
        heap_array = NULL;
    }
};

void MaxHeap::Heapify(int index) // bottom up heapification
{
    if (index == -1)
    {
        return;
    }
    int parent = index;
    int lc = getLeftChild(parent);
    int rc = getRightChild(parent);
    if (lc < length && heap_array[parent].priority < heap_array[lc].priority)
    {
        parent = lc;
    }
    if (rc < length && heap_array[parent].priority < heap_array[rc].priority)
    {
        parent = rc;
    }
    //temp variables
    int t_p = heap_array[index].priority;
    string t_n = heap_array[index].name;
    // swapping parent with child
    heap_array[index].priority = heap_array[parent].priority;
    heap_array[index].name = heap_array[parent].name;
    // swapping child with parent
    heap_array[parent].priority = t_p;
    heap_array[parent].name = t_n;
    
    Heapify(index-1);
}

void MaxHeap::HeapSort(int index)
{
    int last_pos = length - 1;
    // swapping the element to be removed with the last element    
    heap_array[index].priority = heap_array[last_pos].priority;
    heap_array[index].name = heap_array[last_pos].name;
    // deleting last element
    heap_array[last_pos].priority = -1;
    heap_array[last_pos].name = "";
    // decrementing length
    length--;
}

// You can use the main function below to test your implementation
// Remember to comment out the main section before running test_1.cpp and test_2.cpp

// int main() {

// }