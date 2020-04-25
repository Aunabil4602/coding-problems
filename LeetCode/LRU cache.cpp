struct node{
    int key,val;
    node *next,*prev;
    node(){
        next=prev=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,node*> val;
    node *root,*foot;
    int cnt,capacity;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        cnt=0;
        root=foot=NULL;
    }
    
    void create(int key,int value){
        node* x=new node;
        x->key=key;
        x->val=value;
        if(val[key]!=NULL){
            remove(val[key]);
        }
        val[key]=x;
        add(x);
        if(cnt>capacity){
            val[foot->key]=NULL;
            remove(foot);
        }
    }
    
    void remove(node* x){
        if(x->prev!=NULL)x->prev->next=x->next;
        if(x->next!=NULL)x->next->prev=x->prev;
        if(x==root)root=x->next;
        if(x==foot)foot=x->prev;
        
        cnt--;
    }
    
    void add(node* x){
        if(root==NULL){
            root=x;
            foot=x;
        }
        else {
            x->next=root;
            if(root!=NULL)root->prev=x;
            root=x;
        }
        cnt++;
    }
    
    int get(int key) {
        if(val[key]==NULL)return -1;
        create(val[key]->key,val[key]->val); 
        return val[key]->val;
    }
    
    void put(int key, int value) {
        create(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
