/* Queue operatons are as follows:

1. Enqueue - O(1)
2. Dequeue - O(n)
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
        return back == -1;
    }

    //enqueue - O(1)
    void push(int data){
        if(back == size-1){
            cout<<"Overflow, Queue is full"<<endl;
            return;
        }
        arr[++back] = data;
        if(front == -1){
            front++;
        }
    }

    //dequeue - O(n)
    void pop(){
        if(front > back || front==-1){
            cout<<"Underflow, Queue is empty"<<endl;
            return;
        }
        
        for (int i = 0; i < back; i++) {
            arr[i] = arr[i + 1];
        }
        back--;
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
        int i=0;
        while(i<=back){
            cout<<arr[i]<<" ";
            i++;
        }
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

    cout<<"Size of the Queue is : "<<q.getSize()<<'\n';
    cout<<"is the queue empty: "<<q.isEmpty()<<'\n';
    q.display();

    cout<<"removed element from Peek : "<<q.peek()<<endl; q.pop();
    q.display();

    q.push(5);
    q.display();

    while(!q.isEmpty()){
        cout<<q.peek()<<endl;
        q.pop();
    }

    cout<<"is the queue empty: "<<q.isEmpty()<<'\n';
}
