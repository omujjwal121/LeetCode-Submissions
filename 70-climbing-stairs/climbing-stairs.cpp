class Solution {
public:
    int answer(int n, vector<int>&dp)
    {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int left = answer(n-1,dp);
        int right = answer(n-2, dp);
        return dp[n]=left+right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return answer(n,dp);
    }
};