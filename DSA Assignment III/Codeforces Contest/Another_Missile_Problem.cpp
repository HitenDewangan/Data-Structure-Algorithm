#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<double> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    vector<int> kills(n);
    for(int i=0; i<n; i++){
        cin>>kills[i];
    }

    double sum = 0;
    for(int i=0; i<n; i++){
        if(kills[i] >= m){
            sum += p[i];
        }
    }


    for(int i=0; i<n; i++){
        if(kills[i] < m){
            cout<< fixed << setprecision(9)<<0.0<<" ";
        }
        else{
            cout<< fixed << setprecision(9);
            cout<<(p[i]/sum)<<" ";
        } 
    }
    cout<<endl;

}