class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> mp;
        for(auto c:nums) mp[c]++;
        vector<int>ans;
        for(auto c:mp)
        {
            if(c.second == 1 and mp[c.first-1]==0 and mp[c.first+1]==0) ans.push_back(c.first);
        }
        return ans;
    }
};