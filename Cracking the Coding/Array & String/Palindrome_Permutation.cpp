/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat", "atco eta " , etc.)
*/

/*Logic I applied: To store the characters of this string in a set s1 and then comparing the size of set s1 and the size of string s depending on whether it is even or odd length */

#include<iostream>
#include<set>
#include <string>
#include <algorithm>
#include<ctype.h>

using namespace std;

bool isPalindromePermutation(string s){

    //removing all duplicate characters 
    set<char> s1;
    for(char c : s){
        if(isalpha(c)) {
            s1.insert(c);       //use tolower() if strings are not in lowercase
        }
    }

       int oddFrequencies = 0;
    for (auto const& ch : s1) {
        oddFrequencies += count(s.begin(), s.end(), ch) % 2;
    }

    return (oddFrequencies <= 1);

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    
    if(isPalindromePermutation(s)){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
    

    return 0;
}

//Status : Done
//Time Complexity : O(n)
//Space Complexity : O(n) due to the set that might hold up to n unique characters in the worst case.