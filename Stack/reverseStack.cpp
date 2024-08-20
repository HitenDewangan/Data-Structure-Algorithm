#include<iostream>
#include<stack>
using namespace std;

// function to push at the bottomof the stack
void pushAtBottom(int data, stack<int>& st){  // Time : O(n^2) | Space : O(n) -> recursive stack

    if(st.empty()){
        st.push(data);
        return;
    }
    int top = st.top();
    st.pop();
    pushAtBottom(data, st);
    st.push(top);
}

void reverse(stack<int>& st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();
    reverse(st);
    pushAtBottom(top, st);   // 3 2 1
}

int main(){
    // Creating a stack
    stack<int> st;

    // push elements
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<"top : "<<st.top()<<endl;

    reverse(st);

    cout<<"Size :" <<st.size()<<endl;
    cout<<"reversed stack :"<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}