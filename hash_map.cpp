// Author: Sarah Grossheim
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
	// Declare a map with string keys and int values
	map<string, int> hashMap;

	// Insert elements
	hashMap["Thousand Island"] = 0;
	hashMap["Ranch Dressing"] = 1;
	hashMap["Italian       "] = 2;
	hashMap["Blue Cheese"] = 3;
	hashMap["Vinaigrette"] = 4;

	// Another way to insert elements in a map
	hashMap.insert(pair<string, int>("Caesar Dressing", 5));

	// Access and print values in the map using an iterator
	map<string, int>::iterator itr;
	cout << "Printing keys and values... " << endl << endl;	
	cout << "Key:			Value:" << endl;
	for(itr = hashMap.begin(); itr != hashMap.end(); itr++){
		cout << itr->first << "		" << itr->second << endl;
	}
	cout << endl << endl;

	// Search for two specific keys
	string salad1 = "Thousand Island";
	string salad2 = "Ketchup";
	
	cout << "Searching for " << salad1 << "..." << endl;
	if(hashMap.find(salad1) != hashMap.end())
		cout << salad1 << " is in the map." << endl << endl;
	else 
		cout << salad1 << " is not in the map." << endl << endl;
	
	cout << "Searching for " << salad2 << "..." << endl;
	if(hashMap.find(salad2) != hashMap.end())
		cout << salad2 << " is in the map." << endl << endl;
	else
		cout << salad2 << " is not in the map" << endl << endl;
	
	// Delete the worst salad dressing (Vinaigrette)
	cout << "Deleting the worst salad dressing..." << endl << endl;
	string worstSalad;
	worstSalad = hashMap.erase("Vinaigrette");

	// Display map with deleted item
	cout << "Printing keys and values after deletion..." << endl << endl;
	cout << "Key: 			Value:" << endl;
	for(itr = hashMap.begin(); itr != hashMap.end(); itr++){
		cout << itr->first << "		" << itr->second << endl;
	}	
	cout << endl;

	// Create a collision
	cout << "Creating a collision..." << endl;
	hashMap["Ranch Dressing"] = 10000;

	cout << "Printing keys and values after collision..." << endl;
	cout << "Key:			Value:" << endl;
	for(itr = hashMap.begin(); itr != hashMap.end(); itr++){
		cout << itr->first << "		" << itr->second << endl;
	}
	cout << "Notice how when the Ranch Dressing key collided, it overrided the new value." << endl;
	cout << "This is because the keys MUST be unique. No two elements can have equivalent keys." << endl;

}


