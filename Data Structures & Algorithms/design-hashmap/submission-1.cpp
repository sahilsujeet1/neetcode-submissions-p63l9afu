#include<list>

class MyHashMap {
private:
    static const int INITIAL_SIZE = 1024;
    int size, count;
    double loadFactor = 0.75;
    vector<list<pair<int,int>>> buckets;

    int hash(int key) {
        return key % size;
    }

    void rehash() {
        int oldSize = size;
        size = oldSize * 2;

        vector<list<pair<int,int>>> newBuckets(size);

        for(int i=0; i<oldSize; i++) {
            for(auto &p: buckets[i]) {
                int idx = p.first % size;
                newBuckets[idx].push_back(p);
            }
        }

        buckets = move(newBuckets);
    }

public:
    MyHashMap() {
        size = INITIAL_SIZE;
        count = 0;
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int index = hash(key);

        // key already exists
        for(auto &p: buckets[index]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }

        // new key
        buckets[index].push_back({key, value});
        count++;

        if((double)(count / size) > loadFactor)
            rehash();
    }
    
    int get(int key) {
        int index = hash(key);

        for(auto &p: buckets[index]) {
            if(p.first == key)
                return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);

        for(auto it=buckets[index].begin(); it != buckets[index].end(); ++it) {
            if(it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */