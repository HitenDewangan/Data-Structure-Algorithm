/*   1.1
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?
*/

#include<iostream>
#include<set>

using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    set<char> s1;

    for(char c : s){
        s1.insert(c);

    }

    if(s1.size() == s.size()){
        cout<<"String has all unique characters";
    }
    else{
        cout<<"String has non-unique characters";
    }

    return 0;
}

// status : Done