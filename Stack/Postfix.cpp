#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string token : tokens) {
        if (isOperator(token[0])) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token[0] == '+')
                st.push(a + b);
            else if (token[0] == '-')
                st.push(a - b);
            else if (token[0] == '*')
                st.push(a * b);
            else if (token[0] == '/')
                st.push(a / b);
        } else {
            int num;
            stringstream ss(token);
            ss >> num;
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "10", "*"};
    cout << evalRPN(tokens) << endl; // Output: 9

    return 0;
}
