#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Heap
{
    public:
        vector<int> a;
        int sz=0;

    // ============================== Parent & Child Functions ==============================
        int parent(int x){
            return(x-1)/2;
        }

        int leftChild(int x){
            return 2*x+1;
        }
        int rightChild(int x){
            return 2*x+2;
        }
    // ============================== Heap Functions ==============================

        // ==================== PUSH ==================== it will automatically heapify. "heapify" means it will maintain the heap property
        void push(int val){
            int ind = sz;
            cout<<"Pushing at index : "<<ind<<endl;
            a.push_back(val);
            sz++;

            while(sz!=0){
                if(a[parent(ind)] < a[ind]){
                    swap(a[parent(ind)], a[ind]);
                    ind = parent(ind);
                }
                else{
                    break;
                }
            }           
        }

        // ==================== TOP ====================
        int top(){
            if(isEmpty()){
                return INT_MIN;
            }
            return a[0];
        }

        // ===================== POP ===================== only possible on the top
        void pop(){
            if(isEmpty()){
                cout<<"Empty"<<endl;
                return;
            }
            a[0] = a[sz-1];
            a.pop_back();
            sz--;
            int ind = 0;
            while(true){
                int curr = a[ind];
                int lc = leftChild(ind) < sz ? a[leftChild(ind)] : INT_MIN;
                int rc = rightChild(ind) < sz ? a[rightChild(ind)] : INT_MIN; 

                int maximum = max({curr, lc, rc});

                if(maximum == curr) break;
                if(maximum == lc){
                    cout<<"swapping it with left child = "<<lc<<endl;
                    swap(a[ind], a[leftChild(ind)]);
                    ind = leftChild(ind);
                }
                else{
                    cout<<"swapping it with right child = "<<rc<<endl;
                    swap(a[ind], a[rightChild(ind)]);
                    ind = rightChild(ind);
                }
            }
        }

        // ===================== EMPTY =====================
        bool isEmpty(){
            return size()==0;
        }

        int size(){
            return sz;
        }

        void display(){
            for(int x: a){
                cout<<x<<" -- ";
            }
            cout<<endl;
        }

} pq;

signed main(){
    cout<<"PUSH operation ================================================"<<endl;
    pq.push(90);
    pq.display();
    pq.push(50);
    pq.display();
    pq.push(70);
    pq.push(15);
    pq.push(35);
    pq.display();
    // cout<<"Till here no pop"<<endl;
    pq.push(75);
    pq.display();
    cout<<"POP operation ============================================="<<endl;
    pq.pop();
    pq.display();
    cout<<"Popping again"<<endl;
    pq.pop();
    pq.display();
}