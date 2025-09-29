// implementation of queue (FIFO - First In, First Out) in c++
#include <iostream>
#include <vector>
using namespace std;

class Queue {
    private:
        int front, rear;
        vector<int> elements;

    public:
        Queue() : front(0), rear(-1) {}

        // Enqueue element to the queue
        void enqueue(int element) {
            elements.push_back(element);
            rear++;
        }

        // Dequeue element from the queue
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow" << endl;
                return -1; // Indicate queue is empty
            }
            int dequeuedElement = elements[front];
            
            // Remove the element from the front
            elements.erase(elements.begin());
            rear--;
            
            // Reset indices if queue becomes empty
            if (elements.empty()) {
                front = 0;
                rear = -1;
            }
            return dequeuedElement;
        }

        // Peek at the front element of the queue
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1; // Indicate queue is empty
            }
            return elements[front];
        }

        // Check if the queue is empty
        bool isEmpty() {
            return front > rear || elements.empty();
        }

        // Get the size of the queue
        int size() {
            return elements.size();
        }

        // Display all elements in the queue (for debugging)
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Queue elements (front to rear): ";
            for (int i = front; i <= rear; i++) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
};