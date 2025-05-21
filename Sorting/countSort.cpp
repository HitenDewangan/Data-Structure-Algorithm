#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

void countSort(vector<int>& arr) {
    int n = arr.size();
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());

    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }

    int j = 0;
    for(int i=mn; i<=mx; i++) {
        if(mp.count(i)) {
            while(mp[i]--){
                arr[j++] = i;
            }
        }
    }
}

int main(){
    // sample 
    vector<int> arr = {3, 2, 4, 6, 4, 2, 3, 4, 3, 6};

    countSort(arr);

    cout<<"Sorted array: "<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }

}