#include<list>
class LRUCache {
public:
    map<int,int>kval;
    map<int,list<int>::iterator>kitr;
    list<int>l;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        kval.clear();
        kitr.clear();
        
    }
    
    int get(int key) {
        if(kval.find(key)==kval.end())return -1;
             int val=kval[key];
            l.erase(kitr[key]);
            l.push_front(key);
            kitr[key]=l.begin();
            return val;
        
    }
    
     void put(int key, int value) {
        if(kval.find(key)==kval.end()){
            if(size==l.size()){
                int temp=l.back();
                kval.erase(temp);
                kitr.erase(temp);
                l.pop_back();
            }
           
        }
        else l.erase(kitr[key]);
               l.push_front(key);
                kval[key]=value;
                kitr[key]=l.begin();
            
        }
    
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */