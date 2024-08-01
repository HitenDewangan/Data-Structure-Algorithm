// ======================================================================================================================
// Problem 1 : Implement Stack using Queues
// Submission Link : https://leetcode.com/problems/implement-stack-using-queues/submissions/1340802602/
class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top_el = q.front();
        q.pop();
        return top_el;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty(); 
    }
};


// ======================================================================================================================
// Problem 2 : Implement Queue using Stacks
// Submission Link : https://leetcode.com/problems/implement-queue-using-stacks/submissions/1340993615/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            int top = s2.top();
            s2.pop();
            return top;
        } else {
            while (!s1.empty()) {
                auto top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                auto top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


// ======================================================================================================================
// Problem 3 : Insert Delete GetRandom O(1)
// Submission Link : https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1340998994/
class RandomizedSet {
public:
    unordered_set<int>st;
    RandomizedSet() {
        st = {};
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end())
            return 0;
        st.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        auto it = st.find(val);
        if(it != st.end())
        {
            st.erase(it);
            return 1;
        }
        return 0;
    }
    
    int getRandom() {
        int n = rand();
        return *next(st.begin(),n%st.size());
    }
};


// =====================================================================================================================
// Problem 4 : Insert Delete GetRandom O(1)- Duplicates allowed
// Submission Link : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/submissions/1341016587/
class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp; //val: {index in arr}
    
    RandomizedCollection() {}
    
    bool insert(int val) {
        arr.push_back(val);
        mp[val].insert(arr.size()-1);
        return mp[val].size() <= 1;
    }
    
    bool remove(int val) {
        if(mp[val].size()==0) return false;
        int ind= *mp[val].begin();
        mp[val].erase(ind);
        
        int num= arr.back();
        swap(arr[ind], arr[arr.size()-1]);
        mp[num].insert(ind);
        mp[num].erase(arr.size()-1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};


// ====================================================================================================================
// Problem 5 : Design Linked List
// Submission Link : https://leetcode.com/problems/design-linked-list/submissions/1341026291/
class MyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int len;

public:
    // Constructor to initialize the linked list
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    // Get the value of the index-th node in the linked list
    int get(int index) {
        if (index < 0 || index >= len) return -1;

        Node* curr = head;
        while (index) {
            curr = curr->next;
            index--;
        }
        return curr->data;
    }

    // Add a node of value val before the first element of the linked list
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (len == 0) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        len++;
    }

    // Append a node of value val to the last element of the linked list
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if (len == 0) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        len++;
    }

    // Add a node of value val before the index-th node in the linked list
    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) return;

        if (index == 0) {
            addAtHead(val);
        } else if (index == len) {
            addAtTail(val);
        } else {
            Node* temp = new Node(val);
            Node* curr = head;
            while (index) {
                curr = curr->next;
                index--;
            }
            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;
            len++;
        }
    }

    // Delete the index-th node in the linked list
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;

        if (index == 0) {
            if (len == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
        } else if (index == len - 1) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            Node* curr = head;
            while (index) {
                curr = curr->next;
                index--;
            }
            Node* temp = curr;
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete temp;
        }
        len--;
    }
};


// =================================================================================================================
// Problem 6 : Online Stock Span
// Submission Link : https://leetcode.com/problems/online-stock-span/submissions/1341042374/
class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// ================================================================================================================
// Problem 7 : Design a Stack With Increment Operation
// Submission Link : https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/1341044347/
class CustomStack {
    int size;
    vector<int> arr;
public:
    CustomStack(int maxSize) {
       size = maxSize;
    }
    
    void push(int x) {
        if(arr.size() < size)
            arr.push_back(x);
    }
    
    int pop() {
        if(arr.size() == 0)
            return -1;
        else{
            int res=arr.back();
            arr.pop_back();
            return res;
        }
        
    }
    
    void increment(int k, int val) {
        int x = k;
        if(arr.size() < k)
            x = arr.size();
        for(int i=0; i < x; i++){
            arr[i] += val;
        }
    }
};


// ================================================================================================================
// Problem 8 : Design Browser History
// Submission Link : https://leetcode.com/problems/design-browser-history/submissions/1341049006/
class BrowserHistory {
public:
    string homepage;
    vector<string>p;
    int i=0;
    BrowserHistory(string homepage) {
        this->homepage=homepage;
        p.push_back(homepage);
        i=0;
    }
    
    void visit(string url) {
        p.erase(p.begin()+i+1,p.end());
        p.push_back(url);
        i=p.size()-1;
        
    }
    
    string back(int steps) {
        i=i-steps;
        if(i<0)i=0;
        return p[i];
    }
    
    string forward(int steps) {
        i=i+steps;
        if(i>=p.size())i=p.size()-1;
        return p[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */