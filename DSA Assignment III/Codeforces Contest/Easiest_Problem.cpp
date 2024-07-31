#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    int i = 2, ans = k;
    while(ans <= n){
        ans = k*i;
        i++;
    }

    cout<<ans<<endl;
}

// formula : n + (k - (n%k))