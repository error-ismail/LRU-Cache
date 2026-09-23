#include <bits/stdc++.h>
using namespace std;
class Cache{
private:
    struct Node{
        string key;
        int value;
        Node* prev;
        Node* next;
        Node(string key,int value){
            this->key=key;
            this->value=value;
            prev=nullptr;
            next=nullptr;
        }
    };
    int capacity;
    unordered_map<string,Node*>mp;
    Node* head;
    Node* tail;
    void removenode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void add(Node* node){
        node->prev=tail->prev;
        node->next=tail;
        tail->prev->next=node;
        tail->prev=node;
    }
public:
    Cache(int capacity){
        this->capacity=capacity;
        head=new Node("",0);
        tail=new Node("",0);
        head->next=tail;
        tail->prev=head;
    }
    int get(string key){
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];
        removenode(node);
        add(node);
        return node->value;
    }
    void put(string key,int value){
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->value=value;
            removenode(node);
            add(node);
            return;
        }
        Node* node=new Node(key,value);
        mp[key]=node;
        add(node);
        if((int)mp.size()>capacity){
            Node* lru=head->next;
            removenode(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
    ~Cache(){
        Node* current=head;
        while(current!=nullptr){
            Node* next=current->next;
            delete current;
            current=next;
        }
    }
};
int main(){
    int capacity;
    // cout<<"Enter the size of Cache: ";
    cin>>capacity;
    Cache cache(capacity);
    // cout<<"Enter operations(put key value or get key):"<<endl;
    string operation;
    while(cin>>operation){
        if(operation=="put"){
            string key;
            int value;
            cin>>key>>value;
            cache.put(key,value);
        }
        else if(operation=="get"){
            string key;
            cin>>key;
            cout<<cache.get(key)<<endl;
        }
    }
    return 0;
}
