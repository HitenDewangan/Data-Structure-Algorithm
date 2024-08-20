/* Stack implementation and operations
    1. push O(1)
    2. pop  O(1)
    3. top  O(1)
    4. isEmpty  O(1)
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
    public:
        Node* head;  // head will be the top element
        int size;

        // constructor to initialize the stack
        Stack() {this->head = nullptr; this->size = 0;}

        // function to check if the stack is empty
        bool isEmpty(){
            return head == nullptr;
        }

        // function to push an element in the stack
        void push(int data){
            Node* newNode = new Node(data);
            if(isEmpty()){
                head = newNode;
                size++;
                return;
            }
            newNode->next = head;
            head = newNode;
            size++;
        }

        // function to pop an element from the stack
        void pop(){
            if(isEmpty()){
                cout << "\nStack Underflow" << endl;
                return;
            }
            Node* top = head;
            head = head->next;
            delete top;
            size--;
        }

        // function to return the top element
        int top(){
            if(isEmpty()){
                cout << "\nStack Underflow" << endl;
                return -1;
            }
            return head->data;
        }

        // function to return the size of stack
        int getSize(){
            return size;
        }

};

int main(){
    // Creating a stack
    Stack st;

    // push elements
    st.push(1);
    st.push(2);
    st.push(3);
    
    // Print top element of the stack
    cout << "Top element is " << st.top() << endl;

    // getting size
    cout<<"Size of the stack is : "<<st.getSize()<<endl;

    // removing two elemements from the top
    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.top() << endl;

    st.push(4);

    cout<<"Size of the stack is : "<<st.getSize()<<endl;

    while(!st.isEmpty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}