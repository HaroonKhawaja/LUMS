#include "Task_01A.cpp"
#include <stdlib.h>

class TableItem
{
    public:
    
    int key;
    string value;

    TableItem()
    {
        // default state
        key = -1;
        value = "";
    }

    TableItem(int k, string v)
    {
        key = k;
        value = v;
    }
};



class LinearProbing : public TableItem
{
    public:

    int count;
    int table_size;
    TableItem hash_table[1500];


    LinearProbing(int table_size_)
    {
        /*
        Class constructor. Set the table size.

        :param table_size_: table size
        */
       table_size = table_size_;
    }


    int getHash(string value)
    {
        /*
        Generate the compressed hash key corresponding to the given string. The key should not be greater than the table size
        and should not be negative. Use the functions you made in task 01A.

        :param value: the string to be hashed and compressed
        :returns: the compressed hash key
        :rtype: int
        */
        int hk = getHashCode(value);    
        int compressed_hk = divCompression(hk, table_size);
        
        if (compressed_hk < 0)
        {
            compressed_hk = compressed_hk * -1;
        }

        return compressed_hk;
    }


    void resizeTable()
    {
        /*
        Function called in insertWord() function. This will be used to resize the table and remap the strings present in it.
        Choose resize factor of your choice. This will determine the time you take to pass the tests so try different values.

        :rtype: void
        */
        int old_table_size = table_size;
        table_size = table_size*2;

        for (int i = 0; i < old_table_size; i++)
        {
            if (hash_table[i].key != -1)
            {
                int rhk = getHash(hash_table[i].value);
                hash_table[rhk].value = hash_table[i].value;
                hash_table[rhk].key = rhk
                
            }
            
        }
    }

    void insertWord(string value)
    {
        /*
        Insert a string into the hash table at the appropriate position using its hash key.
        Call resizeTable() function here when loadfactor is greater than 2/3
        
        :param value: string to be inserted
        :rtype: void
        */
        int hk = getHash(value);
        while (hash_table[hk].key != -1 && hash_table[hk].value != "") // linear probing
        {
            hk++;
            hk = hk % table_size;
        }
        // initializing values
        hash_table[hk].value = value;
        hash_table[hk].key = hk;
        count++;
        if ((float)count/table_size >= 2.0/3) // resizing table
        {
            resizeTable();
        }
    }

    void deleteWord(string value)
    {
        /*
        Deleted a string from the hash table. After deleting, set the value at that position to "deleted" and the key to -1
        
        :param value: string to be deleted
        :rtype: void
        */

        // // cout << value << endl;
        // int hk = getHash(value);
        // while (hash_table[hk].value != value)
        // {
        //     hk++;
        //     hk = hk % table_size;
        // }
        // hash_table[hk].key = -1;
        // hash_table[hk].value = "deleted";
    }


    bool lookupWord(string value)
    {
        /*
        Searches the hash table for a given string.

        :param value: the string to search for
        :returns: true if the string is present in the hash table, false otherwise
        :rtype: bool
        */
        int hk = getHash(value);
        int i = 0;
        while (i != table_size)
        {
            if (hash_table[hk].key == hk)
            {
                return true;
            }
            hk++;
            hk %= table_size;
            i++;
        }
        return false;
    }

    void printList()
    {
        int count = 0;
        for (int i = 0; i < table_size/2; i++)
        {
            cout << i << " -> " << hash_table[i].value << endl;
            if (hash_table[i].key != -1 && (hash_table[i].value != "deleted" || hash_table[i].value != ""))
            {
                count++;
            }
        }
        cout << count << endl;
    }
};


// int main()
// {
//     
// }
