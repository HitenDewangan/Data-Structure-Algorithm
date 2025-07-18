#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    // Destructor to clear the trie
    ~Trie() { 
        clear(root);
    }
    
    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* current = root;
        
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        
        current->isEndOfWord = true;
    }
    
    // Search for a complete word in the trie
    bool search(const string& word) {
        TrieNode* current = root;
        
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        
        return current->isEndOfWord;
    }
    
    // Check if any word in the trie starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        
        return true;
    }

    // Add these methods to the Trie class
    
    // Delete a word from the trie
    bool deleteWord(const string& word) {
        return deleteHelper(root, word, 0);
    }

    // Get all words with a given prefix
    vector<string> getWordsWithPrefix(const string& prefix) {
        vector<string> words;
        TrieNode* current = root;
        
        // Traverse to the prefix node
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return words; // No words with this prefix
            }
            current = current->children[ch];
        }
        
        // Collect all words from this node
        collectWords(current, prefix, words);
        return words;
    }
    
private:
    // Helper function for deletion
    bool deleteHelper(TrieNode* current, const string& word, int index) {
        if (index == word.length()) {
            if (!current->isEndOfWord) {
                return false; // Word doesn't exist
            }
            current->isEndOfWord = false;
            return current->children.empty();
        }
        
        char ch = word[index];
        if (current->children.find(ch) == current->children.end()) {
            return false; // Word doesn't exist
        }
        
        bool shouldDeleteChild = deleteHelper(current->children[ch], word, index + 1);
        
        if (shouldDeleteChild) {
            delete current->children[ch];
            current->children.erase(ch);
            return !current->isEndOfWord && current->children.empty();
        }
        
        return false;
    }

    // Helper function to collect words
    void collectWords(TrieNode* node, string currentWord, vector<string>& words) {
        if (node->isEndOfWord) {
            words.push_back(currentWord);
        }
        
        for (auto& pair : node->children) {
            collectWords(pair.second, currentWord + pair.first, words);
        }
    }

    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }

};

int main() {
    Trie trie;
    // Example usage of the Trie class
    
    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");
    
    // Search examples
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << endl;
    
    // Prefix examples
    cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'ba': " << (trie.startsWith("ba") ? "Yes" : "No") << endl;
    cout << "Starts with 'ora': " << (trie.startsWith("ora") ? "Yes" : "No") << endl;
    
    return 0;
}