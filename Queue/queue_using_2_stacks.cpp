#include<iostream>
#include<stack>
using namespace std;

class Queue{
public:
    stack<int> s1,s2;

    bool isEmpty(){
        return s1.empty() && s2.empty();
    }

    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        if(s1.empty()){
            cout<<"Empty Queue"<<endl;
            return;
        }
        s1.pop();
    }

    int peek(){
        if(s1.empty()){
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        return s1.top();
    }
};

int main(){
    Queue q;
    q.peek();

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Removing the elements from the Queue : "<<q.peek()<<endl;
    q.pop();
    cout<<"Removing the elements from the Queue : "<<q.peek()<<endl;
    q.pop();

    q.push(5);
    cout<<"Top element : "<<q.peek()<<endl;

    cout<<"Removing ALL elements from the Queue : "<<endl;
    while(!q.isEmpty()){
        cout<<q.peek()<<endl;
        q.pop();
    }


}