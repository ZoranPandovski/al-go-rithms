
/*
 implementation of LRU paging Algorithm
 uaing doubly linked list, hash(unordered_map)

 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

	

class LRUCache {

	public:
	int csize ;

	list<int> cache;
	//list<int > :: iterator it;
	unordered_map<int,list<int> :: iterator> hash2;
	unordered_map<int,int> hash1;
    LRUCache(int capacity) {
       csize = capacity;
    }
    
    int Get(int key) {

    	if(hash1.find(key) == hash1.end()){
    		return -1;
    	}
    	else{
    		cache.erase(hash2[key]);
    		cache.push_front(key);
    		hash2[key] = cache.begin();
    		return hash1[key];

    	}

    	
    } // end get func
    
    void put(int key, int value) {

    	if(hash1.find(key)==hash1.end()){        // not present in cache

    		if(cache.size() >= csize){  // cache if full
    			int tmp = cache.back();
    			cache.pop_back();
    			cache.push_front(key);
    			hash1.erase(tmp);
    			hash2[key] = cache.begin();
    			hash1[key] = value;

    		}
    		else{
    			cache.push_front(key);
    			hash1[key]  = value;
    			hash2[key]  = cache.begin();
    		}

    	}
    	else{          // if present in cache

    		if(cache.size() >= csize){  // if cache full
    			cache.erase(hash2[key]);
    			cache.push_front(key);
    			hash1[key] = value;
    			hash2[key] = cache.begin();

    		}
    		else{
    			cache.erase(hash2[key]);
    			cache.push_front(key);
    			hash1[key] = value;
    			hash2[key] = cache.begin();
    		}


    	}

    } // end put func



};	  




int main(){

	int n;
	cin>>n;
	LRUCache ob(n);

	ob.put(1,2);
	ob.put(2,3);
	ob.put(1,5);
	ob.put(4,5);
	ob.put(6,7);



	cout<<ob.Get(4)<<endl;
	cout<<ob.Get(1);

	


}
