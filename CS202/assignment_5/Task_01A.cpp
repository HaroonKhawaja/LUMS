#include <iostream>

using namespace std;

int getHashCode(string value)
{
    /*
    Generates a bit-wise hash for a given string object. See manual for the operations to compute this hash.

    :param value: the string to be hashed
    :returns: a hash key corresponding to the parameter string
    :rtype: int
    */
    int bitwise_hash = 0;
    for (int i = 0; i < value.length(); i++)
    {
        char s = value[i];
        bitwise_hash =  bitwise_hash ^ (bitwise_hash << 5) + (bitwise_hash >> 2) + s ;
    }
    return bitwise_hash;
}

int divCompression(int hashcode, int table_size)
{
    /*
    Compresses a hash key to fit within a range bounded by an upper limit.

    :param hashcode: the hashkey to be compressed
    :param table_size: the upper limit to fit the hash key
    :returns: a compressed hash key corresponding to the parameter
    :rtype: int
    */
    return hashcode % table_size;
}

// int main()
// {

// }