// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable {
public:
    HashTable(int initTableSize);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void insert(const DataType& newDataItem, const KeyType& key);
    bool remove(const KeyType& deleteKey);
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    void clear();

    bool isEmpty() const;

    void showStructure() const;

private:
    void copyTable(const HashTable& source);

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};

// Pseudocode:
// Constructor - Creates the empty has table. 
// (Remember you are using a linkedlist)

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
HashTable(int initTableSize){

}

// Pseudocode:
// Copy constructor - Initializes the hash table
// to be equivalent to the HashTable object
// parameter other. Use the copyTable helper
// method to do this.

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
HashTable(const HashTable& other){
	
}

// Pseudocode:
// Overloaded assignment operator
// Sets the hash table to be equivalent to the 
// other HashTable object parameter and returns
// a reference to this object

// Authors:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
HashTable operator=(const HashTable& other){

}

// Pseudocode:
// Destructor - Deallocates the memory used
// to store a hash table.

// Authors:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
~HashTable(){

}

// Pseudocode:
// Inserts the key-value pair into the hash table. 
// Remember that your hash table entries
// are each a linked list.

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
void insert(const DataType& searchKey, DataType& returnItem) const{

}

// Pseudocode:
// Searches the hash table for the data item with 
// the matching key.

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
bool retrieve(const KeyType& searchKey, DataType& returnItem) const{

}

// Pseudocode:
// Searches the hash table for the data item with the key
// deleteKey. If the data item is found, then removes the data
// and returns true. Otherwise, returns false.

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
bool remove(const KeyType& key){

}

// Pseudocode:
// Removes all data items in the hash table

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
void clear(){

}

// Pseudocode:
// Returns true if the hash table is empty, otherwise return false

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
bool isEmpty() const{

}

// Psuedocode:
// Outputs the data items in the hash table. If the hash table 
// is empty, outputs "Empty hash table". Display each entry as a 
// bucket as so:
// Bucket 0: ["key", "value"]
// Hint: The linkedList implementation has things that can help

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
void showStructure() const{

}

// Pseudocode
// Outputs the data items in the hash table. If the hash table
// is empty, outputs "Empty hash table". Display each entry as a 
// bucket as so:
// Bucket 0: ["key", "value"]
// Hint: The linkedList implementation has things that can help

// Author:
// Inputs:
// Outputs:
template <typename DataType, typename KeyType>
void copyTable(const HashTable& source){

}

#endif // ifndef HASHTABLE_H
