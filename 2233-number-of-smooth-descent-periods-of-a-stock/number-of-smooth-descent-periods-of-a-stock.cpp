class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        int i=0;
        while(i<n)
        {
            int ref = prices[i];
            i++;
            long long cnt = 1;
            while(i<n and ref-prices[i] == 1)
            {
                ref = prices[i];
                cnt++;
                i++;
            }
            ans += (cnt*(cnt+1))/2;
        }
        return ans;
    }
};