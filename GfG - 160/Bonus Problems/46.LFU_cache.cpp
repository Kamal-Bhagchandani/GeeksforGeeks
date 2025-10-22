/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/LL-bonus-problem/problem/lfu-cache-1665050355
*/

class Node{
  public:
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;
    
    Node(int key,int value){
        this->key = key;
        this->value = value;
        cnt = 1;
    }
};

class LFUCache {
  public:
    unordered_map<int,Node*> cacheMap;
    unordered_map<int,pair<Node*,Node*>> freqMap;
    int minFreq;
    int capacity;
    
    LFUCache(int cap) {
        // code here
        this->capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        // code here
        if(cacheMap.find(key)==cacheMap.end())
            return -1;
        Node* node = cacheMap[key];
        int res = node->value;
        updateFreq(node);
        
        return res;
    }
        
    void put(int key, int value) {
        // code here
        if(capacity == 0) return;
        if(cacheMap.find(key)!=cacheMap.end()){
            Node* node = cacheMap[key];
            node->value = value;
            updateFreq(node);
        }
        else{
            if(cacheMap.size() == capacity){
                Node* node = freqMap[minFreq].second->prev;
                cacheMap.erase(node->key);
                remove(node);
                if(freqMap[minFreq].first->next == freqMap[minFreq].second){
                    freqMap.erase(minFreq);
                }
                delete(node);
            }
            
            Node* node = new Node(key,value);
            cacheMap[key] = node;
            minFreq = 1;
            add(node,1);
        }
    }
    
    void add(Node* node, int freq){
        if(freqMap.find(freq)==freqMap.end()){
            Node* head = new Node(-1,-1);
            Node* tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            freqMap[freq]={head,tail};
        }
        Node* head = freqMap[freq].first;
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    
    void remove(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    void updateFreq(Node* node){
        int oldFreq = node->cnt;
        node->cnt++;
        remove(node);
        
        if(freqMap[oldFreq].first->next==freqMap[oldFreq].second){
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq){
                minFreq++;
            }
        }
        add(node,node->cnt);
    }
};