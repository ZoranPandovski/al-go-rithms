#include<bits/stdc++.h>
#include<list>
using namespace std;

/*
hashmap - add(key, value)
          get(key)
          chaining
          delete(key)
          set(key, value)

*/

class HashNode{
public:
    int key;
    int value;
public:
    HashNode(int k, int val){
        key = k;
        value = val;
    }

};

class HashMap{

private:
    int sz;
    int capacity;
    vector<list<HashNode*>> table;

    int hashCode(int key){
        return key % capacity;
    }

public:

    HashMap(int c){
        capacity = c;
        for(int i = 0; i<c; i++){
            list<HashNode*> l;
            table.push_back(l);
        }
        sz = 0;
    }

    void add(int key, int value){
        int hashIndex = hashCode(key);
        HashNode* newNode = new HashNode(key, value);
        list<HashNode*> :: iterator it;
        for(it = table[hashIndex].begin(); it != table[hashIndex].end(); it++){
            if((*it)->key == key){
                (*it)->value = value;
                return;
            }
        }
        table[hashIndex].push_front(newNode);

    }

    int get(int key){

        int hashIndex = hashCode(key);
        list<HashNode*> :: iterator it;
        for(it = table[hashIndex].begin(); it != table[hashIndex].end(); it++){
            if((*it)->key == key){
                return (*it)->value;
            }
        }
        return -1;
    }

    void delete_(int key){

        int hashIndex = hashCode(key);
        list<HashNode*> :: iterator it;
        for(it = table[hashIndex].begin(); it != table[hashIndex].end(); it++){
            if((*it)->key == key){
                table[hashIndex].erase(it);
                cout<<"successfully removed"<<endl;
                return;
            }
        }
        cout<<"not found"<<endl;

    }

    void display(){
        for(int i = 0; i<capacity; i++){

            list<HashNode*> lis = table[i];
            list<HashNode*> :: iterator it;
            cout<<"index "<<i<<endl;
            for(it = lis.begin(); it != lis.end(); it++){
                cout<<(*it)->key<<" "<<(*it)->value<<endl;
            }
        }

    }

};




int main(){

    HashMap mapp(10);
    mapp.add(10, 20);
    mapp.add(12, 23);
    mapp.add(10, 15);
    mapp.add(20, 8);
    mapp.add(99, 9);
    mapp.display();

    cout<<endl;
    mapp.delete_(10);
    mapp.delete_(99);
    mapp.display();


}


