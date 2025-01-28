/* Queue implementation using Doubly Linked List*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Queue{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue(){front = NULL; rear = NULL; size = 0;}

    void push(int data){
        Node* newNode = new Node(data);
        newNode->prev = nullptr;
        if(front == nullptr){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    void pop(){
        if(front == nullptr){
            cout<<"Underflow, Queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front != nullptr){
            front->prev = nullptr;
        }
        delete temp;
        size--;
    }

    int peek(){
        if(front == nullptr){
            cout<<"Underflow, Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return size == 0;
    }

    int getSize(){
        return size;
    }

    void display(){
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" <-- ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Size of the Queue is : "<<q.getSize()<<endl;

    cout<<"peek element : "<<q.peek()<<endl;

    q.display();

    cout<<"Removing the elements from the Queue : "<<endl;
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }

    cout<<"is the queue empty: "<<q.empty()<<endl;
    cout<<"Size of the Queue is : "<<q.getSize()<<endl;
}