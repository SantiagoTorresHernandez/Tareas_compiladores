//Desarrolla y/o documenta una implementación apropiada para las siguientes clases: STACK (lifo), QUEUE (fifo),
// TABLE/HASH/DICTIONARY (order),.. (* las puedes implementar “desde 0” o usar alguna librería “pública” *)
// Las clases deben contener métodos para soportar las principales operaciones de acceso y manipulación (clásicas). NO
// tienen que ser clases, si el lenguaje de desarrollo no las soporta.

#include <iostream>
#include "stack.cpp"
#include "queue.cpp"
#include "hash.cpp"
using namespace std;

int main() {
    cout << "=== Data Structures Implementation ===" << endl << endl;

    // Example usage of Stack (LIFO)
    cout << "1. STACK (LIFO):" << endl;
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Top element is: " << stack.peek() << endl; // Should print 30
    cout << "Stack size is: " << stack.size() << endl;   // Should print 3

    cout << "Popped element is: " << stack.pop() << endl; // Should print 30
    cout << "Stack size after pop is: " << stack.size() << endl; // Should print 2
    stack.display();
    cout << endl;

    // Example usage of Queue (FIFO)
        cout << "2. QUEUE (FIFO):" << endl;
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    
    cout << "Front element is: " << queue.peek() << endl; // Should print 10
    cout << "Queue size is: " << queue.size() << endl;   // Should print 3
    cout << "Dequeued element is: " << queue.dequeue() << endl; // Should print 10
    cout << "Queue size after dequeue is: " << queue.size() << endl; // Should print 2
    queue.display();
    cout << endl;

    // Example usage of HashTable
    cout << "3. HASH TABLE (Order):" << endl;
    HashTable hashTable;
    
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(12, "Twelve"); // Collision with key 2 if hashSize is 10
    hashTable.insert(-5, "Negative Five"); // Test negative key
    hashTable.insert(22, "Twenty Two"); // Another collision test
    
    cout << "Hash table size: " << hashTable.size() << endl;
    cout << "Is empty? " << (hashTable.isEmpty() ? "Yes" : "No") << endl;
    
    cout << "Search key 2: " << hashTable.search(2) << endl; // Should print "Two"
    cout << "Search key 12: " << hashTable.search(12) << endl; // Should print "Twelve"
    cout << "Search key -5: " << hashTable.search(-5) << endl; // Should print "Negative Five"
    cout << "Contains key 22? " << (hashTable.contains(22) ? "Yes" : "No") << endl;
    
    hashTable.display();
    
    cout << "\nRemoving key 2..." << endl;
    bool removed = hashTable.remove(2);
    cout << "Key 2 removed: " << (removed ? "Yes" : "No") << endl;
    cout << "Search key 2 after removal: " << hashTable.search(2) << endl; // Should indicate key not found
    cout << "Hash table size after removal: " << hashTable.size() << endl;
    
    hashTable.display();

    return 0;
}
