/*  1.3 
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)

EXAMPLE
Input: "Mr 3ohn Smith 13
Output: "Mr%203ohn%20Smith"

*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            s.replace(i, 1, "%20");
        }
    }

    cout<<s;

}