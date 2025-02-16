#include<iostream>
#include<stack>
using namespace std;

int prec(char c){ // for precedence, so that higher precedence operators are evaluated first
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

/* STEPS TO SOLVE :
    1. Create an empty stack.
    2. Read the expression from left to right.
    3. If the character is operand, add it to the answer.
    4. If the character is '(', push it to the stack.
    5. If the character is ')', pop the stack and add it to the answer until you see a '('.
    6. If the character is an operator, pop the stack and add it to the answer until you see an operator with lower precedence.
*/

string infixToPostfix(string s){
    stack<char> st;
    string ans=""; 
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(s)<<endl;
    return 0;
}