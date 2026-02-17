class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(auto c:nums) mp[c]++;
        map<int, vector<int>>uni;
        for(auto c:mp) uni[c.second].push_back(c.first);
        map<int, bool>candi;
        for(auto c: uni) if(c.second.size()==1) candi[c.second[0]] = true;
        for(auto c:nums) if(candi[c]) return c;
        return -1;
    }
};