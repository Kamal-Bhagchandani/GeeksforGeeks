/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-bonus-problems/problem/longest-valid-word-with-all-prefixes
*/

struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        isEnd = false;
        fill(begin(children), end(children), nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& word){
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        
        node->isEnd = true;
    }
    
    bool allPrefixesExist(string& word){
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            node = node->children[idx];
            
            if(!node || !node->isEnd)
                return false;
        }
        
        return true;
    }
};

class Solution {
  public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;
        for(string& word : words){
            trie.insert(word);
        }
        
        string res = "";
        
        for(string& word : words){
            if(trie.allPrefixesExist(word)){
                if(word.length() > res.length() ||
                  (word.length() == res.length() && word < res)){
                    res = word;
                }
            }
        }
        
        return res;
    }
};
