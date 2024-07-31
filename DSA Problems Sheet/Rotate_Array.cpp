/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;

    int* arr=new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    k %= n;

    for(int i=0; i<k; i++){
        int temp = arr[n-1];
        for(int j=n-1; j>0; j--){
            arr[j] = arr[j-1]; 
        }
        arr[0] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;

    return 0;

}

//Time complexty = O(n) by using k mod n
//space complexity = O(n)