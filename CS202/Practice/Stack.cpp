#include<iostream>
using namespace std;

template<typename tp>
class Stack
{
    private:
        int max_size = 10;
        int* array = NULL;
    public:
        Stack();
        void push(tp x);
        tp pop();

        tp Top();
        bool empty();
        void print();
};

// Push
template<typename tp>
Stack<tp>::Stack()
{
    array = new int[max_size];
}
template<typename tp>
void Stack<tp>::push(tp x)
{
    max_size++;
    array[0] = x;
}
template<typename tp>
tp Stack<tp>::pop()
{
    tp remove = array[0];
    for(int i = 0; i < max_size-1; i++)
    {
        array[i] = array[i+1];
    }
    return remove;
}
template<typename tp>
tp Stack<tp>::Top()
{

}
template<typename tp>
bool Stack<tp>::empty()
{

}
template<typename tp>
void Stack<tp>::print()
{
    for(int i = 0; i < max_size; i++)
    {
        cout << array[0] << " ";
    }
    cout << endl ;
}
int main()
{
    Stack<char> char_s;
    char_s.push(1);
    char_s.push(2);
    char_s.push(3);
    char_s.print();

    return 0;
}