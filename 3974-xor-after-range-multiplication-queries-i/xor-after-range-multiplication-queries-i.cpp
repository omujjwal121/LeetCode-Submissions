class Solution {
public:
    int xorAfterQueries(vector<int>& numss, vector<vector<int>>& queries) {
        int n = numss.size();
        int q = queries.size();
        int mod = 1e9+7;
        vector<long long>nums;
        for(auto c: numss) nums.push_back(c);
        for(int i=0;i<q;i++)
        {
            int idx = queries[i][0];
            while(idx <= queries[i][1])
            {
                nums[idx] = (nums[idx] * queries[i][3]) % mod;
                idx += queries[i][2];
            }
            // for(auto c:nums) cout<<c<<' ';cout<<endl;
        }
        int ans = 0;
        for(auto c:nums) ans = ans ^ c;
        return ans;
    }
};