#include <iostream>
using namespace std;

class MinStack {
private:
    struct Node {
        int value;
        int min;
        Node* next;
        Node(int x, int min, Node* next) : value(x), min(min), next(next) {}
    };
    Node* head;

public:
    MinStack() : head(nullptr) {}

    void push(int x) {
        if (head == nullptr) {
            head = new Node(x, x, nullptr);
        } else {
            head = new Node(x, min(x, head->min), head);
        }
    }

    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top() {
        if (head != nullptr) {
            return head->value;
        }
        throw runtime_error("Stack is empty");
    }

    int getMin() {
        if (head != nullptr) {
            return head->min;
        }
        throw runtime_error("Stack is empty");
    }
};


// ====================== M A I N ======================
int main() {
    MinStack* obj = new MinStack();
    
    // cout << obj->top() << endl;
    // cout << obj->getMin() << endl;

    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    cout<<obj->top() << endl;
    obj->pop();
    cout << obj->top() << endl;
}