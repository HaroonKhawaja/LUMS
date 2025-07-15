#include "Task_01A.cpp"
#include "LinkedList.cpp"
#include <stdlib.h>

class Chaining
{
    public:

    int table_size;
    LinkedList hash_table[750];

    Chaining(int n)
    {
        /*
        Class constructor. Set the table size.

        :param n: table size
        */
        table_size = n; 
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

    void insertWord(string value)
    {
        /*
        Insert a string into the hash table at the correct location (based on the hash key of the string).

        :param value: the string to be inserted
        :rtype: void
        */
        int hk = getHash(value);
        hash_table[hk].addAtHead(value);
    }

    bool lookupWord(string value)
    {
        /*
        Check if a given string is in the hash table.

        :param value: the string to be searched
        :returns: true if the string is present, false otherwise
        :rtype: bool
        */
        int hk = getHash(value);
        bool is_present = hash_table[hk].isPresent(value);
        return is_present;
    }

    void deleteWord(string value)
    {
        /*
        Delete a string from the hash table. Return without doing anything if the string is not present.

        :param value: the string to be deleted
        :rtype: void
        */
        int hk = getHash(value);
        hash_table[hk].deleteFromValue(value);
    }
};

// int main()
// {
//     
// }