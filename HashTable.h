// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable 
{
public:
    HashTable(int initTableSize);
    HashTable(const HashTable<DataType, KeyType>& other);
    HashTable<DataType, KeyType>& operator=(const HashTable<DataType, KeyType>& other);

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

// Author: Paul
// Inputs: Table Size
// Outputs: No output, just initializes variables and makes enough space in memory for all the variables. 
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new LinkedList<DataType, KeyType>[tableSize];
}

// Pseudocode:
// Copy constructor - Initializes the hash table
// to be equivalent to the HashTable object
// parameter other. Use the copyTable helper
// method to do this.

// Author: Paul
// Inputs: A hash table to copy the values from
// Outputs: None
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable<DataType, KeyType>& other)
{
	tableSize = other.tableSize;
	copyTable(other);
	
}

// Pseudocode:
// Overloaded assignment operator
// Sets the hash table to be equivalent to the 
// other HashTable object parameter and returns
// a reference to this object

// Authors: Sarah
// Inputs: A templated HashTable 
// Outputs: Returns a HashTable with the values from the passed table copied into it. 
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable<DataType, KeyType>& other){
	clear();
	tableSize = other.tableSize;
	copyTable(other);
}

// Pseudocode:
// Destructor - Deallocates the memory used
// to store a hash table.

// Authors: Sarah
// Inputs: None
// Outputs: None
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	clear();
	delete[] dataTable;
}


// Pseudocode:
// Inserts the key-value pair into the hash table. 
// Remember that your hash table entries
// are each a linked list.

// Author: Paul
// Inputs: A dataItem and a key
// Outputs: None
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem, const KeyType& key)
{
  unsigned int index = newDataItem.hash(key) % tableSize;
  cout << "Index is " << index << endl;
  dataTable[index].insert(newDataItem, key);
}

// Pseudocode:
// Searches the hash table for the data item with 
// the matching key.

// Author: Sarah
// Inputs: A key and DataItem
// Outputs: Returns if the Value is found using the given key or not  
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
  int index = returnItem.hash(searchKey) % tableSize;
  return dataTable[index].retrieve(searchKey, returnItem);
  
}

// Pseudocode:
// Searches the hash table for the data item with the key
// deleteKey. If the data item is found, then removes the data
// and returns true. Otherwise, returns false.

// Author: Paul
// Inputs: A key to remove
// Outputs: Returns true if values was removed and false otherwise 
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& key)
{
  for(int i = 0; i < tableSize; i++)
  {
    if(dataTable[i].remove(key))
      return true;
  }
  return false;
}

// Pseudocode:
// Removes all data items in the hash table

// Author: Sarah
// Inputs: None
// Outputs: None just clears the enitre hashtable
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
  for(int i = 0; i < tableSize; i++)
     {
       dataTable[i].clear();
     }
  tableSize = 0;
}

// Pseudocode:
// Returns true if the hash table is empty, otherwise return false

// Author: Paul
// Inputs: None
// Outputs: Returns true if the hashTable is empty and false otherwise
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
 
  for(int i = 0; i < tableSize; i++)
    {
      if(!dataTable[i].isEmpty())
        return false;
    }
  return true;
}

// Psuedocode:
// Outputs the data items in the hash table. If the hash table 
// is empty, outputs "Empty hash table". Display each entry as a 
// bucket as so:
// Bucket 0: ["key", "value"]
// Hint: The linkedList implementation has things that can help

// Author: Sarah
// Inputs: None
// Outputs: Just prints the Key value pairs of the hashTable sequentially IF the table is not empty
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const{
  
  if(isEmpty())
      cout << "HashTable is Empty!" << endl;
  else 
  {
      for (int i = 0; i < tableSize; i++) 
      {
          cout << "Bucket " << i << ": ";
          dataTable[i].showStructure();
          cout << endl;
      }
  }

}

// Pseudocode
// Outputs the data items in the hash table. If the hash table
// is empty, outputs "Empty hash table". Display each entry as a 
// bucket as so:
// Bucket 0: ["key", "value"]
// Hint: The linkedList implementation has things that can help

// Author: Paul
// Inputs: A hashTable to copy the values from 
// Outputs: None just copies the values from the input and stores it into our table. 
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source){

	for(int i = 0; i < tableSize; i++)
	{
		dataTable[i] = source.dataTable[i];
	}
}

#endif // ifndef HASHTABLE_H

