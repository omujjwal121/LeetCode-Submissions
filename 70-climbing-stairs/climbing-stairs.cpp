class Solution {
public:
    int ans(int n, vector<int>&dp)
    {
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        int first = ans(n-1, dp); 
        int second = ans(n-2, dp);
        return dp[n]=first+second; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        return ans(n, dp);
    }
};