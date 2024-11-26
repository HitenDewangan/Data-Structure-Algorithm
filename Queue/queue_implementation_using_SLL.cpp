/*Implentation of Queue using Linked List*/


#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* front;
    Node* back;
    int size;
public:
    Queue(){front = NULL; back = NULL; size = 0; }

    void push(int data){
        Node* newNode = new Node(data);
        if(front == nullptr){
            front = back = newNode;
        }
        else{
            back->next = newNode;
            back = newNode;
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
        if(front == nullptr){
            back = nullptr;
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
        return front == nullptr;
    }

    void display(){
        Node* temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" <-- ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void getSize(){
        cout<<size<<endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Size of the Queue is : ";
    q.getSize();

    cout<<"peek element : "<<q.peek()<<endl;

    q.display();

    cout<<"Removing the elements from the Queue : "<<endl;
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }

    cout<<"is the queue empty: "<<q.empty()<<endl;
    cout<<"Size of the Queue is : ";
    q.getSize();

}