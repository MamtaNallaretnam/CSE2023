#include <iostream>
#include <chrono> // include chrono library for measuring time
#define SIZE 100 // define maximum size of stack

using namespace std;
using namespace chrono;      

class Stack {
    private:
        int top; // index of the top element in stack
        int arr[SIZE]; // array to store elements of stack

    public:
        Stack() { top = -1; } // constructor to initialize stack

        bool is_empty() { return top == -1; } // check if stack is empty

        void push(int x) {
            if (top == SIZE - 1) { // check if stack is full
                cout << "Error: Stack overflow\n";
                return;
            }
            arr[++top] = x; // insert element and update top index
        }

        int pop() {
            if (is_empty()) { // check if stack is empty
                cout << "Error: Stack underflow\n";
                return -1;
            }
            return arr[top--]; // return top element and update top index
        }

        int peek() {
            if (is_empty()) { // check if stack is empty
                cout << "Error: Stack empty\n";
                return -1;
            }
            return arr[top]; // return top element without removing it
        }

        int size() { return top + 1; } // return number of elements in stack
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


