class Fancy {
public:
    vector<long long>v;
    Fancy() {
        vector<int>v;
    }
    
    void append(int val) {
        v.push_back(val);
    }
    
    void addAll(int inc) {
        for(int i=0;i<v.size();i++) v[i]+=inc;
    }
    
    void multAll(int m) {
        for(int i=0;i<v.size();i++)
        {
            v[i]*=m;
            int mod = 1e9+7;
            v[i] = v[i] % mod;
        }
    }
    
    int getIndex(int idx) {
        if(idx>=v.size()) return -1;
        return v[idx];
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */