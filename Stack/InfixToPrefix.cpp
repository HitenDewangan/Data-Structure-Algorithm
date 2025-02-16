// Infix to Prefix Expression
#include<iostream>
#include<stack>
#include<algorithm>
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
    1. Reverse infix, swap parentheses.
    2. Scan reversed infix: operands to output, '(' to stack, ')' pop stack to '(', operators push/pop based on precedence (handling right-associativity).
    3. Pop remaining stack operators to output.
    4. Reverse output for prefix.
*/

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    stack<char> st;
    string ans=""; 

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
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

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixToPrefix(s)<<endl;
    return 0;
}