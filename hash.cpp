// implementation of a hash table (order) in C++
#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
using namespace std;

class HashTable {
    private:
        static const int hashSize = 10; // size of the hash table
        vector<list<pair<int, string>>> table; // vector of lists to handle collisions
        int count; // number of elements

        // compute index for a key using hash function
        int hashFunction(int key) {
            return abs(key) % hashSize; 
        }

    public:
        HashTable() : table(hashSize), count(0) {}

        // Insert key-value pair into the hash table
        void insert(int key, const string& value) {
            int index = hashFunction(key);
            // Check if the key already exists and update the value
            for (auto& pair : table[index]) {
                if (pair.first == key) {
                    pair.second = value;
                    return; // key updated, no need to increment count
                }
            }
            // if key does not exist, add new key-value pair
            table[index].emplace_back(key, value);
            count++;
        }

        // remove key-value pair from the hash table
        bool remove(int key) {
            int index = hashFunction(key);
            auto& cell = table[index];
            for (auto it = cell.begin(); it != cell.end(); ++it) {
                if (it->first == key) {
                    cell.erase(it);
                    count--;
                    return true; // Successfully removed
                }
            }
            cout << "Key not found" << endl;
            return false; 
        }

        // Search for a value by key in the hash table
        string search(int key) {
            int index = hashFunction(key);
            for (const auto& pair : table[index]) {
                if (pair.first == key) {
                    return pair.second;
                }
            }
            return "Key not found"; 
        }

        // Check if a key exists in the hash table
        bool contains(int key) {
            int index = hashFunction(key);
            for (const auto& pair : table[index]) {
                if (pair.first == key) {
                    return true;
                }
            }
            return false;
        }

        // Get the number of elements in the hash table
        int size() {
            return count;
        }

        // Check if the hash table is empty
        bool isEmpty() {
            return count == 0;
        }

        // Display the contents of the hash table
        void display() {
            cout << "Hash Table Contents:" << endl;
            for (int i = 0; i < hashSize; i++) {
                cout << "Bucket " << i << ": ";
                if (table[i].empty()) {
                    cout << "empty";
                } else {
                    for (const auto& pair : table[i]) {
                        cout << "{" << pair.first << ": " << pair.second << "} ";
                    }
                }
                cout << endl;
            }
            cout << "Total elements: " << count << endl;
        }

        // Clear all elements from the hash table
        void clear() {
            for (auto& bucket : table) {
                bucket.clear();
            }
            count = 0;
        }
};