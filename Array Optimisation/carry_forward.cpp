#include<iostream>
using namespace std;

int pairsum(char arr[],int n){
    int ans = 0, a_count = 0, ga_count=0;
    for(int i=n-1; i>=0; i--){
        if(arr[i] == 'a'){
            ans += ga_count;
            a_count++;
        }
        else if(arr[i] == 'g'){
            ga_count += a_count;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<pairsum(arr,n)<<endl;
}