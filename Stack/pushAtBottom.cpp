#include<iostream>
#include<stack>
using namespace std;

// function to push at the bottomof the stack
void pushAtBottom(int data, stack<int>& st){   // Time : O(n) | Space : O(1)

    if(st.empty()){
        st.push(data);
        return;
    }
    int top = st.top();
    st.pop();
    pushAtBottom(data, st);
    st.push(top);
}

int main(){
    // Creating a stack
    stack<int> st;

    // push elements
    st.push(1);
    st.push(2);
    st.push(3);

    pushAtBottom(7, st);

    pushAtBottom(9, st);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

/*The space complexity of pushing an element at the bottom of a stack is O(1) because no extra variables are used.*/