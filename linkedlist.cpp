// 
#include <iostream>
#include <chrono> // include chrono library for measuring time

using namespace std;
using namespace chrono;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() { top = nullptr; } // constructor to initialize stack

        bool is_empty() { return top == nullptr; } // check if stack is empty

        void push(int x) {
            Node* new_node = new Node; // create a new node
            new_node->data = x; // set the data of the new node
            new_node->next = top; // link the new node to the current top node
            top = new_node; // update the top node to be the new node
        }

        int pop() {
            if (is_empty()) { // check if stack is empty
                cout << "Error: Stack underflow\n";
                return -1;
            }
            Node* temp = top; // store the top node in a temporary variable
            int data = temp->data; // get the data of the top node
            top = top->next; // update the top node to be the next node in the list
            delete temp; // free memory used by the old top node
            return data; // return the data of the old top node
        }

        int peek() {
            if (is_empty()) { // check if stack is empty
                cout << "Error: Stack empty\n";
                return -1;
            }
            return top->data; // return the data of the top node without removing it
        }

        int size() {
            int count = 0;
            Node* temp = top;
            while (temp != nullptr) { // traverse the linked list
                count++;
                temp = temp->next;
            }
            return count;
        }
};

void prints (Stack s){
    if (s.is_empty()){
        return;
    }
    
    int x = s.peek();
    s.pop();

    prints(s);
    cout << x << " ";
    
    s.push(x);

}

int main() {
    Stack s;
    auto start = high_resolution_clock::now(); // get start time
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    prints(s);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    prints(s);
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    prints(s);

    cout << endl;

    auto stop = high_resolution_clock::now(); // get stop time
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration
    
    cout << "Time taken by : " << duration.count() << " microseconds" << endl;

    

    return 0;
}

