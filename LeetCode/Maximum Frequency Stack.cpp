struct obj{
    int total, pos, val;
    obj(int t, int p, int v) {
        this->total = t;
        this->pos = p;
        this->val = v;
    }
};

struct cmp {
    bool operator() (obj* a, obj* b) const {
        if (a->total>b->total)return true;
        else if (a->total<b->total) return false;
        else {
            return a->pos > b->pos;
        }
    }
};


class FreqStack {
public:
    set<obj*, cmp> s;
    map<int, vector<int>> m;
    int cnt;
    
    FreqStack() {
        cnt = 0;
    }
    
    void push(int val) {
        // cout<<"push - "<<val<<endl;
        if (m[val].size()>0) {
            s.erase(new obj(m[val].size(), m[val].back(), val));
        }
        
        m[val].push_back(cnt);
        s.insert(new obj(m[val].size(), cnt, val));
        cnt++;
    }
    
    int pop() {
        // cout<<"pop "<<endl;
        auto o = *(s.begin());
        int val = o->val;
        
        s.erase(new obj(m[val].size(), m[val].back(), val));
        m[val].pop_back();
        if (m[val].size()> 0)s.insert(new obj(m[val].size(), m[val].back(), val));
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
