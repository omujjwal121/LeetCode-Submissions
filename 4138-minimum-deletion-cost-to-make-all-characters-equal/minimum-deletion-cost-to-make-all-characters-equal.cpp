class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char, long long> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]+=cost[i];
        long long total = 0;
        for(auto c:mp) total+= c.second;
        long long ans = 100000000000000000;
        for(auto c:mp) ans = min(ans, total - c.second);
        return ans;
    }
};