#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {        
    private:
        Node* top;

    public:
        Stack() { 
            top = NULL; 
        }

        bool is_empty() { 
            return top ==NULL; 
        }

        void push(int value) {                //implementing push function
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = top;
            top = new_node;
        }

        int pop() {
            if (is_empty()) {
                cout << "Error: Stack underflow\n";
                return -1;
            }
            Node* temp = top;
            int data = temp->data;           //popping elements by giving the value
            top = top->next;
            delete temp;
            return data;
        }

        int peek() {
            if (is_empty()) {
                cout << "Error: Stack empty\n";
                return -1;
            }
            return top->data;
        }

        int size() {
            int count = 0;
            Node* temp = top;
            while (temp != NULL) {
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
