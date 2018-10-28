#pragma once
#include <iostream>
#include <string>

template<class T>
class LinkedList
{
    struct Node
    {
        T data;
        Node *next = nullptr, *prev = nullptr;

        //Node() { next = nullptr; prev = nullptr; data = T(); }
    };

    Node *head, *tail;
    unsigned int count;

public:
    //=====Accessors=====//
    void print() const
    {
        if (count == 0)
            return;

        Node* curr = head;
        for (unsigned int i = 0; i < count; i++)
        {
            std::cout << i + 1 << " " << curr->data << std::endl;
            curr = curr->next;
        }
    }

    void print_matches(T &data)
    {
        Node *curr = head;
        bool found = false;

        for (unsigned int i = 0; i < count; i++)
        {
            if (curr == nullptr || curr->data == T())
                break;
            else if (((std::string)curr->data).find((std::string)(data)) != std::string::npos)
            {
                std::cout << i + 1 << " " << curr->data << std::endl;
                found = true;
            }   

            curr = curr->next;
        }

        if (!found)
            std::cout << "not found" << std::endl;
    }

    unsigned int size() const
    {
        return count;
    }

    struct Node* at(unsigned int index)
    {
        if (index >= count)
            return nullptr;
        
        Node* curr = head;
        for (unsigned int i = 0; i < count; i++)
        {
            if (i == index)
                return curr;
            
            curr = curr->next;
        }

        return nullptr;
    }

    struct Node* get(T &data)
    {
        if (count == 0)
            return nullptr;
        
        Node* curr;
        for (unsigned int i = 0; i < count; i++)
        {
            curr = this->at(i);
            if (curr->data == data)
                return curr;
        }

        return nullptr; // if reached, list doesn't contain data
    }

    bool contains(T &data)
    {
        if (this->get(data) == nullptr)
            return false;
        else
            return true;
    }

    //=====Insertion=====//
    void add(T &data) // defaults to end of list
    {
        Node *temp = new Node();
        temp->data = data;

        if (head == nullptr)
        {
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
        }
        else if (tail == head)
        {
            temp->prev = head;
            temp->next  = nullptr;
            head->next = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
        }
        
        count++;
    }

    void add_head(T &data)
    {
        if (head == nullptr)
            add(data);
        
        else
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = head;
            temp->prev = tail;
            head = temp;
            count++;
        }
    }
    
    void add(T *data, unsigned int size) // defaults to end of list
    {
        for (unsigned int i = 0; i < size; i++)
            add(data[i]);
    }

    void insert(unsigned int index, T &data)
    {
		if (index > count)
			return;
		else if (index == count || head == nullptr)
			add(data);
		else if (index == 0)
			add_head(data);
        else
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = at(index);
            temp->prev = at(index)->prev;
            at(index)->prev->next = temp;
            at(index)->prev = temp;
            count++;
        }
    }

    void insert(unsigned int index, T *data, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            insert(index, data[i]);
            index++;
        }
    }

    //=====Removal=====//
    void pop() // this function exists for quick removal
    {
        Node *temp = tail->prev;
        tail->prev = nullptr;
        temp->next = nullptr;
        delete tail;
        tail = temp;
        count--;
    }

    void remove_at(unsigned int index)
    {
        if (index >= count)
            return; // throw "Out of bounds";
        else if (head == nullptr)
            return;
        else if (index == 0)
        {
            Node *temp = head->next;
            head->next = nullptr;
            temp->prev = nullptr;
            delete head;
            head = temp;
        }
        else if (index == count - 1)
        {
            Node *temp = tail->prev;
            delete tail; 
            tail = temp;
        }
        else
        {
            Node *target = this->at(index);
            target->prev->next = target->next;
            target->next->prev = target->prev;
            target->next = nullptr;
            target->prev = nullptr;
            delete target;
        }

        count--;

    }

    void remove(T &data)
    {
        if (count == 0)
            return;
        
        Node *target = this->get(data);
        if (target == nullptr)
            return;
        else if (target == head)
        {
            if (head->next == nullptr)
            {
                delete head; 
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node *temp = head->next;
                temp->prev = nullptr;
                head->next = nullptr;
                delete head;
                head = temp;
            }
        }
        else if (target == tail)
        {
            Node *temp = tail->prev;
            temp->next = nullptr;
            tail->prev = nullptr;
            delete tail;
            tail = temp;
        }
        else
        {
            target->prev->next = target->next;
            target->next->prev = target->prev;
            target->next = nullptr;
            target->prev = nullptr;
            delete target;
        }

        count--;
    }

    void clear()
    {
        Node *curr = head;
        Node *temp;
        while (count != 0)
        {
            temp = curr->next;
            delete curr;
            curr = temp;
            count--;
        }

        head = nullptr;
        tail = nullptr;
    }

    //====Helper Functions====//
    void set(const LinkedList<T> &other)
    {
        this->clear();
        this->count = 0;

        const Node *curr = other.head;
        while (curr != nullptr)
        {
            this->add(curr->data);
            curr = curr->next;
        }
    }

    //=====Operators=====//
    const T &operator[](unsigned int index) const
    {
        if (index > count)
            return NULL; // throw "Error!";

        Node *curr = at(index);

        return curr->data;
    }

    T &operator[](unsigned int index)
    {
        if (index > count)
            throw "Error!";

        Node *curr = at(index);

        return curr->data;
    }

    bool operator==(const LinkedList<T> &rhs) const
    {
        if (this->count != rhs.count)
            return false;

        unsigned int matches = 0;
        for (unsigned int i = 0; i < count - 1; i++)
        {
        const Node *curr1 = at(i);
        const Node *curr2 = rhs.at(i);
            if (curr1->data == curr2->data)
                matches++;
        }

        if (matches == count - 1)
            return true;
        else
            return false;
    }

    LinkedList<T> &operator=(const LinkedList<T> &rhs)
    {
        set(rhs);

        return *this;
    }

    //=====Constructors / Destructor=====//
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    LinkedList(const LinkedList<T> &list)
    {
        set(list);
    }

    ~LinkedList()
    {
        clear();
        if (head != nullptr)
            delete head;
        if (tail != nullptr && tail != head)
            delete tail;
    }
};
