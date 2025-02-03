/*  1.2
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.
*/
#include<iostream>
#include<algorithm>
using namespace std;


bool isPermutation(string str1, string str2) {
  if (str1.length() != str2.length()) {
    return false;
  }

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  if(str1 == str2){
    return true;
  }

  return false;
}


int main(){
    string s1,s2;
    cout<<"Enter first strings: ";
    cin>>s1;
    cout<<"Enter second strings: ";
    cin>>s2;

    cout << "Both strings are permutation of each other : " << isPermutation(s1, s2) << endl;

    return 0;
}

//status : Done