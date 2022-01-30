#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

unsigned int hashFunction(char const* key, int table_size)
{
    unsigned int hashCode = 0;

    for (int i = 0; *key; i++) {
        unsigned int b;
        if (i % 2 == 0) {
            b = (hashCode << 7) ^ (*key) ^ (hashCode >> 3);
        }
        if (i % 2 == 1) {
            b = (hashCode << 11) ^ (*key) ^ (hashCode >> 5);
            b = ~b;
        }
        key++;
        hashCode = hashCode ^ b;

    }


    return (hashCode & 0x7FFFFFFF) % table_size;
}

class UnorderedMap
{
private:
    //define your data structure here
    //define other attributes e.g. bucket count, maximum load factor, size of table, etc. 
    unsigned int bucketCount;
    double lf;
    int capacity;

    class MapNode {
        string key;
        string value;
        int position;
        MapNode* next;
        MapNode() : key("end"), value("end"), position(NULL) {}
        MapNode(string k, string v, int p) : key(k), value(v), position(p) {}
        friend class UnorderedMap;
    };

    vector<MapNode*>* table;

public:
    class Iterator;
    UnorderedMap(unsigned int bucketCount, double loadFactor);
    ~UnorderedMap();
    UnorderedMap::Iterator begin() const;
    Iterator end() const;
    std::string& operator[] (std::string const& key);
    void rehash();
    void remove(std::string const& key);
    unsigned int size();
    double loadFactor();

    class Iterator
    {
        vector<MapNode*>* bucketPointer;
        MapNode* pointer;
        MapNode* end;
        queue<MapNode*> elements;
        unsigned int bc;
    public:
        //this constructor does not need to be a default constructor;
        //the parameters for this constructor are up to your discretion.
        //hint: you may need to pass in an UnorderedMap object.
        Iterator()
        {
            pointer = new MapNode();
        }
        Iterator(UnorderedMap map)
        {
            bc = map.bucketCount;
            bucketPointer = map.table;
            for (int i = 0; i < map.bucketCount; i++) {
                if (!(map.table + i)->empty()) {
                    pointer = (map.table + i)->front();
                    end = (map.table + i)->back();
                    break;
                }
            }
            for (int i = 0; i < map.bucketCount; i++) {
                if (!(map.table + i)->empty()) {
                    for (int j = 0; j < (map.table + i)->size(); j++) {
                        if ((map.table + i)->at(j) == pointer) {
                            continue;
                        }
                        elements.push((map.table + i)->at(j));
                    }
                }
            }
        }
        Iterator& operator=(Iterator const& rhs)
        {
            this->pointer = rhs.pointer;
            return *this;
        }
        Iterator& operator++()
        {
            if (!elements.empty()) {
                pointer = elements.front();
                elements.pop();
            }
            else {
                pointer->value = "end";
            }
            return *this;
        }
        bool operator!=(Iterator const& rhs)
        {
            return this->pointer->value != rhs.pointer->value;
        }
        bool operator==(Iterator const& rhs)
        {
            return this->pointer == rhs.pointer;
        }
        std::pair<std::string, std::string>  operator*() const
        {
            pair<string, string> data(this->pointer->key, this->pointer->value);
            return data;
        }
        friend class UnorderedMap;
    };
};

UnorderedMap::UnorderedMap(unsigned int bucketCount, double loadFactor)
{
    this->bucketCount = bucketCount;
    lf = loadFactor;
    capacity = 0;
    table = new vector<MapNode*>[bucketCount];
}

UnorderedMap::~UnorderedMap()
{

}

UnorderedMap::Iterator UnorderedMap::begin() const
{
    return Iterator(*this);
}

UnorderedMap::Iterator UnorderedMap::end() const
{
    // iterate to one past or nullptr
    return Iterator();
}

std::string& UnorderedMap::operator[] (std::string const& key)
{

    const char* char_array;
    char_array = &key[0];
    int index = hashFunction(char_array, bucketCount);
    for (int i = 0; i < (table + index)->size(); i++) {
        if ((table + index)->at(i)->key == key) {
            return (table + index)->at(i)->value;
        }
    }
    MapNode* temp = new MapNode(key, "", index);
    (table + index)->push_back(temp);
    capacity++;
    if (loadFactor() >= lf) {
        rehash();
    }
    return temp->value;

}

void UnorderedMap::rehash()
{
    vector<MapNode*>* newTable = new vector<MapNode*>[bucketCount * 2];

    for (int i = 0; i < bucketCount; i++) {
        *(newTable + i) = *(table + i);
    }
    bucketCount *= 2;
    table->clear();
    table = newTable;
}

void UnorderedMap::remove(std::string const& key)
{
    const char* char_array;
    char_array = &key[0];
    int index = hashFunction(char_array, bucketCount);


    for (int i = 0; i < (table + index)->size(); i++) {
        if ((table + index)->at(i)->key == key) {
            (table + index)->erase((table + index)->begin() + i);
            capacity--;
        }
    }
}

unsigned int UnorderedMap::size()
{
    return capacity;
}

double UnorderedMap::loadFactor()
{
    return ((double)capacity / bucketCount);
}

//implement other operators in Iterator class

// Unordered maps are associative containers that store elements 
// formed by the combination of a key value and a mapped value, 
// and which allows for fast retrieval of individual elements based on their keys.

int main()
{
    int lines = 0, buckets = 0;
    double maxLoadFactor = 0.0;
    std::string command = "", ufid = "", name = "", key = "";
    std::cin >> lines >> buckets >> maxLoadFactor;
    UnorderedMap myMap = UnorderedMap(buckets, maxLoadFactor);
    while (lines--)
    {
        std::cin >> command;
        if (command == "hash")
        {
            std::cin >> key;
            const char* convertedKey = key.c_str();
            std::cout << hashFunction(convertedKey, buckets) << "\n";
        }
        else if (command == "insert")
        {
            std::cin >> ufid >> name;
            myMap[ufid] = name;
        }
        else if (command == "size")
        {
            std::cout << myMap.size() << "\n";
        }
        else if (command == "load")
        {
            std::cout << std::fixed << std::setprecision(2) << myMap.loadFactor() << "\n";
        }
        else if (command == "search")
        {
            std::cin >> ufid;
            std::cout << myMap[ufid] << "\n";
        }
        else if (command == "traverse")
        {
            auto it = myMap.end();
            for (UnorderedMap::Iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
            {
                std::cout << (*iter).first << " " << (*iter).second << "\n";
            }

            // This should also work
                //for (auto tableEntry: myMap)
                //{
                //    std::cout << tableEntry.first << " " << tableEntry.second << "\n";
                //}

        }
        else if (command == "remove")
        {
            std::cin >> ufid;
            myMap.remove(ufid);
        }
    }

    return 0;
}