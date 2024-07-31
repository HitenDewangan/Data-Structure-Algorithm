#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int sdisk, newApp;          // disk size and new app size
    cout<< "Enter disk size and new app size : " << endl;
    cin>>sdisk>>newApp;

    if(newApp > sdisk){
        cout<< "Not possible, App size is greater than disk size" << endl;
    }
    

    cout<< "Apps already on disk : " << endl;
    int n;
    cin>>n;

    int *a = new int[n];

    int empty_space = sdisk;
    cout<<"Enter app sizes on disk : " << endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
        empty_space -= a[i];            // updating the empty space after giving space to installed apps
    }

    // sort the array, so that app with max size is at the front
    sort(a, a+n, greater<int>());  // sorting in descending order

    // int empty_space = sdisk;
    // for(int i=0; i<n; i++){
    //     empty_space -= a[i];          
    // }

    cout<<"Empty space : " << empty_space << endl;
    if(empty_space >= newApp){
        cout<<"App can be installed without any deletion" << endl;
        return 0;
    }

    // check if the app can be installed
    int count = 0;

    cout<<"Apps to delete : " << endl;


    for(int i=0; i<n; i++){
        if(empty_space < newApp){ 
            empty_space += a[i];         // after deletion of app, its space got added up into the empty space
            count++;
        }
        else{
            break;
        }
    }
    
    cout<< count << endl;

    return 0;
}