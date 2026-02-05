class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>>v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        map<int , bool>mp;
        long long ans = 0;
        for(auto c:v)
        {
            if(mp[c.second]) continue;
            else
            {
                ans+=c.first;
                mp[c.second] = true;
                mp[c.second-1] = true;
                mp[c.second+1] = true;
            }
        }
        return ans;
    }
};