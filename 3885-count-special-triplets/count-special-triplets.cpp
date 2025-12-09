class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto c:nums) mp[c]++;
        map<int, int> left;
        long long ans = 0;
        for(auto c:nums)
        {
            int m = c*2;
            long long l = left[m];
            long long r = mp[m] - left[m];
            if(c==0) r--;
            ans+=l*r;
            left[c]++;
        }
        long long mod = 1e9+7;
        return ans%mod;
    }
};