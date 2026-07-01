#include <string>
#include <vector>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;

    bool searchInNode(string& word, int index, TrieNode* curr) {
        if (index == word.length()) {
            return curr->isWord;
        }
        
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    if (searchInNode(word, index + 1, curr->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        } 
        else {
            int i = c - 'a';
            if (curr->children[i] == nullptr) {
                return false; 
            }
         
            return searchInNode(word, index + 1, curr->children[i]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};