#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> pr;
vector<bool> s(1000001, true);

void seive() {
    s[0] = s[1] = false;
    for (long long i = 2; i < 1000001; i++) {
        if (s[i]) {
            if(i!=2) pr.push_back(i);
            for (long long j = i * i; j < 1000001; j += i) {
                s[j] = false;
            }
        }
    }
}

int main() {
    long long n;
    cin >> n;

    if(n < 38) {
        cout << "No";
    } else {
        seive();
        bool ans = false;
        n = n - 4;

        for(int i = 0; i < pr.size();i++){
            if(pr[i] > sqrt(n)) break;
            int x = sqrt(n - pow(pr[i] , 2));
            if(x == pr[i] || (pow(x , 2) + pow(pr[i] , 2) != n) ) continue;
            if(binary_search(pr.begin() , pr.end() , x)){
                cout<<"Yes";
                return 0;
            }
        }
        cout<<"No";
    }
}