// Driver program
#include<iostream>
#include "hash.hpp"
using namespace std;

int main()
{
    int a[] = {15, 11, 27, 8, 12, 7, 18};
    int n = 7;

    // 7 is count of buckets in hash table
    HashTable ht(7);

    // insert the keys into the hash table.
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);

    }

    cout<< "Contents of the hash table are"<<endl;

    ht.printTable();

    cout<<endl;

    return 0;
}
