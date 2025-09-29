// Stack LIFO implementation in C++ 
#include <iostream>
#include <vector>
//#include "stack.h"
using namespace std;

class Stack {
    private:
        vector<int> elements;

    public:
        Stack() {}

        // Push element onto stack
        void push(int element) {
            elements.push_back(element);
        }

        // Pop element from stack
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1; // Indicate stack is empty
            }
            int poppedElement = elements.back();
            elements.pop_back();
            return poppedElement;
        }

        // Peek at the top element of the stack
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1; // Indicate stack is empty
            }
            return elements.back();
        }

        // Check if the stack is empty
        bool isEmpty() {
            return elements.empty();
        }

        // Get the size of the stack
        int size() {
            return elements.size();
        }

        // Display all elements in the stack 
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack elements (top to bottom): ";
            for (int i = elements.size() - 1; i >= 0; i--) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
};
