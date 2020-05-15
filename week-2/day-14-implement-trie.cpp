//   Implement Trie (Prefix Tree)
// Solution
// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

class Trie {
    Trie* children[26];
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (auto i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for (auto c : word) {
            if (!(curr->children[c - 'a'])) {
                curr->children[c - 'a'] = new Trie;
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        for (auto c : word) {
            curr = curr->children[c - 'a'];
            if (!(curr)) {
                return false;
            }
        }
        if (curr->isEnd) {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (auto c : prefix) {
            curr = curr->children[c - 'a'];
            if (!(curr)) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */