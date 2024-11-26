/* Queue operatons are as follows:

1. Enqueue - O(1)
2. Dequeue - O(1)
3. Front - O(1) - peek
4. back() - O(1)
5. isEmpty - O(1)
6. size - O(1)
7.emplace() - O(1)

*/

#include<iostream>
using namespace std;

// #define n 7

class Queue{
    int size;
    int front;
    int back;
    int *arr;

public:
    // Constructor to initialize the queue
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        back = -1;
    }

    // Destructor to free the allocated memory
    ~Queue() { delete[] arr; }


    bool isEmpty(){
        return front==-1 && back==-1;
    }

    bool isFull(){
        return (back+1)%size==front;
    }

    //enqueue - O(1)
    void push(int data){
        if(isFull()){
            cout<<"Overflow, Queue is full"<<endl;
            return;
        }
        back = (back+1)%size;
        arr[back] = data;
        // for first element
        if(front == -1){
            front++;
        }
    }

    //dequeue - O(1)
    void pop(){
        if(isEmpty()){
            cout<<"Underflow, Queue is empty"<<endl;
            return;
        }
        
        //single element condition [front = back = 0]
        if(front == back){
            front = back = -1;
        }
        else{
            front = (front+1)%size;
        }
    }

    //peek - O(1)
    int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    //display
    void display(){
        int i=front;
        while(i != back){
            cout<<arr[i]<<" ";
            i = (i+1)%size;
        }
        cout<<arr[back];
        cout<<endl;
    }

    int getSize(){
        return size;
    }
};

int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.display();

    cout<<"Removing the elements from the Queue : "<<q.peek()<<endl;
    q.pop();
    q.push(6);
    cout<<"Removing the elements from the Queue : "<<q.peek()<<endl;
    q.pop();
    q.push(7);

    q.display();

    while(!q.isEmpty()){
        cout<<q.peek()<<endl;
        q.pop();
    }

    cout<<"is the queue empty: "<<q.isEmpty()<<'\n';
}
