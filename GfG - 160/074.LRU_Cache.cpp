/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/lru-cache
*/

class LRUCache {
  private:
    int capacity;
    list<pair<int,int>> List;
    
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;
    
  public:
    LRUCache(int cap) {
        // code here
        this->capacity=cap;
    }

    int get(int key) {
        // code here
        auto it=cacheMap.find(key);
        if(it==cacheMap.end()){
            return -1;
        }
        int value=it->second->second;
        List.erase(it->second);
        List.push_front({key,value});
        cacheMap[key]=List.begin();
        return value;
    }

        
    void put(int key, int value) {
        // code here
        auto it=cacheMap.find(key);
        if(it!=cacheMap.end()){
            List.erase(it->second);
            cacheMap.erase(it);
        }
        List.push_front({key,value});
        cacheMap[key]=List.begin();
        
        if(cacheMap.size()>capacity){
            auto lastNode=List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};