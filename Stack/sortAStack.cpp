#include<iostream>
#include<stack>
using namespace std;

void adjust(stack<int>& s, int x){   // this func. will put the lement at its correct place
    if(s.empty() || s.top() < x ){
        s.push(x);
        return;
    }
     
    int top = s.top();
    s.pop();
    adjust(s, x);
    s.push(top);
}

void sort(stack<int>& s)
{
   if(s.size() <= 1){
       return;  // A stack with 0 or 1 element is already sorted
   }
   else{
       int top = s.top();
       s.pop();
       sort(s);
       adjust(s, top);
   }
}


int main(){
    // Creating a stack
    stack<int> st;

    // push elements
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    // original stack : 11 2 32 3 41

    cout<<"top : "<<st.top()<<endl;

    sort(st);

    cout<<"reversed stack :"<<endl;
    cout<<"size : "<<st.size()<<endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout<<endl;

}