/*  1.5 
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.

EXAMPLE
p a l e , pie -> true
p a l e s , pale -> true
p a l e , bale -> true
p a l e , bake -> false*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string isOneEditAway(string s1, string s2) {

    if(abs(s1.length() - s2.length()) > 1){
        return "False";
    }

}

int main(){
    string s1, s2;
    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;

    cout<<isOneEditAway(s1, s2);
}

not done