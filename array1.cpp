#include <iostream>
#define MAX_SIZE 100 // define maximum size of stack

using namespace std;

class Stack {
    private:
        int top; // index of the top element in stack 
        int arr[100]; // array to store elements of stack

    public:
        Stack() { 
            top = -1; 
        } // constructor to initialize stack

        bool is_empty() { 
            return top == -1; 
        } // check if stack is empty

        void push(int x) {
            if (top == MAX_SIZE - 1) { // check if stack is full
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
    //int num;
    //cin >> num;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "The stack: ";
    prints(s);
    
    cout << endl;
    cout << "Size of stack: " << s.size() << endl;
    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "after popping : ";
    prints(s);
    cout << endl;
    cout << "Top element after popping : " << s.peek() << endl;

    s.push(4);
    cout << "after pushing : ";
    prints(s);
    cout << endl;
    cout << "Top element after pushing: " << s.peek() << endl;

    return 0;
}