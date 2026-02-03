class Solution {
public:
    bool ans(int n, vector<int>&stones, int curr, int last, map<int, int>&mp, vector<vector<int>> &dp)
    {
        if(curr == n) return true;
        bool left = false, mid = false, right = false;
        if(dp[curr][last] != -1) return dp[curr][last];
        if(mp[stones[curr]+last-1] and last-1)left = ans(n, stones,mp[stones[curr]+last-1] , last-1, mp, dp);
        if(mp[stones[curr]+last])mid = ans(n, stones, mp[stones[curr]+last], last, mp, dp);
        if(mp[stones[curr]+last+1])right = ans(n, stones, mp[stones[curr]+last+1], last+1, mp, dp);
        return dp[curr][last] = left or mid or right;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]-stones[0]>1) return false;
        map<int ,int>mp;
        for(int i=0;i<n;i++) mp[stones[i]] = i;
        vector<vector<int>> dp(2004, vector<int> (10000, -1));

        return ans(n-1, stones, 1, 1, mp, dp);
    }
};