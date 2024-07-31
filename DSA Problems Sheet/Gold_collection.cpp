// Codechef : https://www.codechef.com/problems/GOLDTRIP

#include<iostream>
#include<vector>
using namespace std;

vector<int> CalcprefixSum(int n, int* arr){
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    
    return prefixSum;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	
	    int *arr = new int[n];
	    for(int i=0;i<n; i++){
	        cin>>arr[i];
	    }
	    
	   vector<int> prefixSum = CalcprefixSum(n, arr);
	 
	    int q;
	    cin>>q;
	    
	    while(q--){
	        int start, finish;
            cin>>start>>finish;
            
            int sum = prefixSum[finish] - prefixSum[start - 1];
            
            cout<<sum<<endl;
            }
            
	    }
	
	 
}
