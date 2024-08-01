#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class OpenAddressingHashMap {
public:
    OpenAddressingHashMap(int size = 100, string probing = "linear")
        : size(size), probing(probing), table(size, {"", ""}) {}

    bool insert(const string& key, const string& value) {
        int i = 0;
        while (i < size) {
            int index = _probe(key, i);
            if (table[index].first == "" || table[index].first == "deleted") {
                table[index] = {key, value};
                return true;
            }
            i++;
        }
        throw runtime_error("HashMap is full");
    }

    bool find(const string& key) {
        int i = 0;
        while (i < size) {
            int index = _probe(key, i);
            if (table[index].first == "") {
                return false;
            }
            if (table[index].first != "deleted" && table[index].first == key) {
                return true;
            }
            i++;
        }
        return false;
    }

    void remove(const string& key) {
        int i = 0;
        while (i < size) {
            int index = _probe(key, i);
            if (table[index].first == "") {
                return;
            }
            if (table[index].first != "deleted" && table[index].first == key) {
                table[index].first = "deleted";
                return;
            }
            i++;
        }
    }

private:
    int size;
    string probing;
    vector<pair<string, string>> table;

    int hash_function(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

    int _probe(const string& key, int i) {
        if (probing == "linear") {
            return (hash_function(key) + i) % size;
        } else if (probing == "quadratic") {
            return (hash_function(key) + i * i) % size;
        }
        return -1; // Should never reach here
    }
};

class SeparateChainingHashMap {
public:
    SeparateChainingHashMap(int size = 100) : size(size), table(size) {}

    void insert(const string& key, const string& value) {
        int index = hash_function(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool find(const string& key) {
        int index = hash_function(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                return true;
            }
        }
        return false;
    }

    void remove(const string& key) {
        int index = hash_function(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }

private:
    int size;
    vector<list<pair<string, string>>> table;

    int hash_function(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }
};


int main() {
    // Open Addressing with Linear Probing
    OpenAddressingHashMap oa_hashmap(10, "linear");
    oa_hashmap.insert("key1", "value1");
    cout << oa_hashmap.find("key1") << endl;  // Outputs: 1 (true)
    oa_hashmap.remove("key1");
    cout << oa_hashmap.find("key1") << endl;  // Outputs: 0 (false)

    // Separate Chaining
    SeparateChainingHashMap sc_hashmap(10);
    sc_hashmap.insert("key1", "value1");
    cout << sc_hashmap.find("key1") << endl;  // Outputs: 1 (true)
    sc_hashmap.remove("key1");
    cout << sc_hashmap.find("key1") << endl;  // Outputs: 0 (false)

    return 0;
}
