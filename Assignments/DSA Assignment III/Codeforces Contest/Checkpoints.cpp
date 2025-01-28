#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;

    map<int, int> mp;

    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        mp[k]++;
    }

    for(int i=0; i<q; i++){
        string str; int num;
        cin>>str>>num;

        if(str == "ADD"){
            mp[num]++;
        }
        else{
            mp[num]--;

            if(mp[num] == 0){
                mp.erase(num);
            }
        }

        cout<<mp.rbegin()->first - mp.begin()->first<<endl;

    }


    

    


}