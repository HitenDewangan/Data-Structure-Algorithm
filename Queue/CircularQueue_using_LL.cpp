#include<iostream>
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
public:
    Node* head;
    Node* tail;
    int size;

    Queue(){ head = tail = nullptr; size = 0;}

    void push(int data){
        Node* newNode = new Node(data); // create a newNode
        if(size == 0){
            head = tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
        size++;
    }

    void pop(){
        if(size == 0){
            cout<<"Empty Queue"<<endl;
            return;
        }

        Node* temp = head;
        tail->next = head->next;
        head = head->next;
        delete temp;
        size--;
    }

    int peek(){
        if(head == nullptr){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    
};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"Size of the Queue is : "<<q.size<<endl;
    cout<<"Peek element is : "<<q.peek();

    cout<<"\nPop element is : "<<q.peek()<<endl;
    q.pop();

    cout<<"\nPeek element is : "<<q.peek();
    
    cout<<"\nSize of the Queue is : "<<q.size<<endl;
    
}