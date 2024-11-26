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
                st.push(max(a,b) / min(a,b));
        } else {
            int num;
            stringstream ss(token);  // stringstream is used to convert string to integer
            ss >> num;
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "10", "*"};
    cout << evalRPN(tokens) << endl; // Output: 30

    // 10 5 / 2 * 3 + 1 - 4 * 2 / 2 + = 6

    vector<string> tokens2 = {"10", "6", "9", "3", "+", "11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens2) << endl; // Output: 22

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "/", "*"};
    cout << evalRPN(tokens3) << endl; // Output: 20

    return 0;
}
