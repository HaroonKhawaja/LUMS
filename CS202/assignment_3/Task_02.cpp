#include <iostream>
#include <iomanip>
#include "test_func.cpp"

using namespace std;

Node* recursiveStore(int* arr, int& size, Node* root)
{
    
    if(root == NULL)
    {
        return root;
    }
    else 
    {
       size--;
    }
    arr[size] = root->data;
    recursiveStore(arr, size, root->left);
    recursiveStore(arr, size, root->right);
}

int RightestLeaf(Node* node)
{
    while(node->right != NULL)
    {
        node = node->left;
    }
    int right_leaf_data = node->data;
    return right_leaf_data;
}


// This is the class you will be populating
class Expedite
{
    public:

    // consider this an object of the BST class you implemented in Task 01
    Test_BST order_record;

    // this array will be used to store the order numbers that are kept on hold while the staff completes the orders in order_record
    int on_hold[10];
    int hold_size = 0;



    // TO-DO Function
        // add the order number to the order records
        // if the order number already exists in the records, reject it
        // if there are already 10 orders in the records, add this order to the end of the on_hold array
    void addOrder(int order_number)
    {
        if(order_record.size() < 10)
        {
            order_record.insert(order_number);
        }
        else
        {
            on_hold[hold_size] = order_number;
            hold_size++;
        }
    }
    

    // TO-DO Function
        // process the first n orders in the records
        // this means that you have to one by one delete an order from the root node of the binary tree and process it
        // return a string with the order numbers of these orders
        // for example, if you delete orders in the sequence 1->2->3, return the string "1 2 3"
        // even if n is larger than the number of orders currently in the record, only process the orders in the record
        // fill in the empty slots with the corresponding number of orders from the end of the on_hold array
string processNOrders(int n)
    {
        string sequence;
        int empty_slots = hold_size;
        Node* temp = order_record.root;

        for(int i = 0; i < n; i++)
        {
            sequence += " " + to_string(order_record.root->data);
            order_record.deleteNode(order_record.root->data);
        }
        sequence = sequence.substr(1, sequence.size() -1);

        while(order_record.size() < 10)
        {
            if(hold_size <= 0)
            {
                break;
            }
            else
            {
                hold_size--;
                order_record.insert(on_hold[hold_size]);
            }
        }
        return sequence;
    }


    // TO-DO Function
        // parse the binary tree to reveal information about the state of the orders record
        // return the following string:
        /*
            "Current orders: x"
            "Capacity for new orders: y"
            "Orders in queue: z"
        */
        // x: number of orders currently in the record
        // y: space left to take new orders (note that there can be max 10 orders at a time)
        // z: inorder traversal of the orders record as implemented in Part 01
        // if the record is empty, z = "none"
        // note that there is a newline character after lines 1 and 2
    string parseOrders()
    {
        string s_return = "";
        int order_record_capacity = 10;

        if(order_record.root == NULL)
        {
            s_return = "Current orders: " + to_string(order_record.size()) +
            "\nCapacity for new orders: " + to_string(order_record_capacity) +
            "\nOrders in queue: none";
        }
        else
        {
            order_record_capacity -= order_record.size();
            s_return = "Current orders: " + to_string(order_record.size()) +
            "\nCapacity for new orders: " + to_string(order_record_capacity) +
            "\nOrders in queue: " + order_record.inorder();
        }
        return s_return;
    }


    // TO-DO Function
        // a customer wants to cancel an order
        // if the order has already been processed, the corresponding order number will no longer be in the record
        // in this case, return the string "Order Processed!"
        // else, delete the order from the record and return the string "Order Canceled ;-;"
        // in case the order is deleted, move in a new order from the end of the on_hold array if there is any
    string cancelOrder(int order_number)
    {
        Node* cancel = order_record.getNode(order_number);
        if(cancel == NULL)
        {
            return "Order Processed!";
        }
        else
        {
            order_record.deleteNode(cancel->data);
            order_record.insert(on_hold[hold_size - 1]);
            hold_size--;
            return "Order Canceled ;-;";
        }
    }


    // TO-DO Function
        // Shift the specified order number up to the root of the order_record so it can be processed immediately
        // adjust the remaining orders so the propoerties of a BST are satisfied
        // you might want to make a helper function for this
        // if the order is already at the root, save computation time and return immediately with the string "Order already at top"
        // otherwise return "Order shifted up"
    string shiftUp(int order_no)
    {
        Node* new_root = order_record.getNode(order_no);
        int new_root_data = order_record.getNode(order_no)->data;

        Node* root = order_record.root;

        if(new_root_data == order_record.root->data)
        {
            return "Order already at top";
        }
        else
        {
            order_record.deleteNode(new_root_data); // deleting the new root order from tree
            int tree_size = order_record.size(); // size to send into recursive function: recursiveStore
            const int SIZE = order_record.size(); // constant size to use for iteration
            int* store_node = new int[tree_size]; // creating an array of tree size

            recursiveStore(store_node, tree_size, order_record.root); // storing all orders except root into an array
            for(int i = 0; i < SIZE; i++)
            {
                order_record.deleteNode(store_node[i]); // deleting all remaining orders
            }
            order_record.insert(new_root_data); // setting new root
            for(int i = 0; i < SIZE; i++)
            {
                order_record.insert(store_node[i]); // inserting all remaining orders
            }

            return "Order shifted up";
        }
    }


    // TO-DO Function
        // add the returned order to the root of the order_record so it can be prepared and sent back to the customer immediately
        // if the order_record exceeds its capacity because of this, remove the right most leaf node and add it to the end of on_hold
    void returnedOrder(int order_no)
    {
        int rleaf_data = RightestLeaf(order_record.root); // store rightest order number
        order_record.insert(order_no); // insert order_no

        if(order_record.size() <= 10) // if order_record size is withing range:
        {
            shiftUp(order_no); // make the order_no the new root
        }
        else if(order_record.size() > 10) // if the order_record size is violated:
        {
            shiftUp(order_no); // make order_no the new root
            order_record.deleteNode(rleaf_data); // delete rightest order number
            on_hold[hold_size] = rleaf_data; // store rightest order number in on_hold array
            hold_size++; // increment on_hold array
        }
    }
};





// You can use the main function to test your implementation
// Please remember to COMMENT OUT this section before running the test files

// int main()
// {
//     Expedite T;

    //// PROCESS ORDER FUNCTION
    // T.order_record.insert(4);
    // T.order_record.insert(2);
    // T.order_record.insert(5);
    // T.order_record.insert(9);
    // T.order_record.insert(3);
    // T.order_record.insert(6);
    // T.order_record.insert(1);
    // T.order_record.insert(8);
    // T.order_record.insert(7);
    // T.order_record.insert(10);
    // T.hold_size = 5;
    // int el = 11;
    // for (int i=0; i<5; i++)
    // {
    //     T.on_hold[i] = el;
    //     el++;
    // }
    // string s = T.processNOrders(3);
    // cout << "Size: " << T.order_record.size() << endl;
    // cout << "order: " << T.order_record.inorder() << endl;
    // cout << "Seq: " << s << endl;
    // cout << "Hold Size: " << T.hold_size << endl;
    // s = T.processNOrders(7);
    // cout << "Size: " << T.order_record.size() << endl;
    // cout << "order: " << T.order_record.inorder() << endl;
    // cout << "Seq: " << s << endl;
    // cout << "Hold Size: " << T.hold_size << endl;

    //// PARSE ORDERS FUNCTION
    // cout << T.parseOrders() << endl;
    // T.addOrder(4);
    // T.addOrder(2);
    // T.addOrder(5);
    // T.addOrder(9);
    // T.addOrder(3);
    // T.addOrder(6);
    // cout << T.parseOrders() << endl;


    //// CANCEL ORDER FUNCTION
    // T.order_record.insert(4);
    // T.order_record.insert(2);
    // T.order_record.insert(5);
    // T.order_record.insert(9);
    // T.order_record.insert(3);
    // T.order_record.insert(6);
    // T.order_record.insert(1);
    // T.order_record.insert(8);
    // T.order_record.insert(7);
    // T.order_record.insert(10);
    // T.hold_size = 2;
    // T.on_hold[0] = 11;
    // T.on_hold[1] = 12;
    // string cancel =  T.cancelOrder(15);
    // cout << T.order_record.size() << endl;
    // cout << T.order_record.inorder() << endl;
    // cout << cancel << endl;
    // cancel =  T.cancelOrder(2);
    // cout << T.order_record.size() << endl;
    // cout << T.order_record.inorder() << endl;
    // cout << cancel << endl;
    // cout << T.hold_size << endl;
    // cout << T.on_hold[0] << endl;

    //// SHIFT UP FUNCTION
    // T.addOrder(4);
    // T.addOrder(2);
    // T.addOrder(5);
    // T.addOrder(9);
    // T.addOrder(3);
    // T.addOrder(6);
    // string shift_up = T.shiftUp(4);
    // cout << "Size: " << T.order_record.size() << endl;
    // cout << T.order_record.inorder() << endl;
    // cout << "Root: " << T.order_record.root->data << endl;
    // cout << shift_up << endl;
    // shift_up = T.shiftUp(9);
    // cout << "Size: " << T.order_record.size() << endl;
    // cout << T.order_record.inorder() << endl;
    // cout << "Root: " << T.order_record.root->data << endl;
    // cout << shift_up << endl;

    //// RETURNED ORDER FUNCTION
    // T.order_record.insert(4);
    // T.order_record.insert(2);
    // T.order_record.insert(5);
    // T.order_record.insert(9);
    // T.order_record.insert(3);
    // T.order_record.insert(6);
    // T.order_record.insert(1);
    // T.order_record.insert(8);
    // T.order_record.insert(7);
    // T.returnedOrder(10);
    // cout << "Size: " << T.order_record.check() << endl;
    // cout << "Root: " << T.order_record.root->data << endl;
    // cout << "Order: " << T.order_record.disp() << endl;
    // cout << "Hold Size: " << T.hold_size << endl;
    // T.hold_size = 2;
    // T.on_hold[0] = 11;
    // T.on_hold[1] = 12;
    // T.returnedOrder(15);
    // cout << "Size: " << T.order_record.check() << endl;
    // cout << "Root: " << T.order_record.root->data << endl;
    // cout << "Order: " << T.order_record.disp() << endl;
    // cout << "Hold Size: " << T.hold_size << endl;
// }