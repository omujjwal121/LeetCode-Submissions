class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        map<int, bool>mp;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int x = nums[i]^nums[j];
                if(mp[x] == false)
                {
                    mp[x] = true;
                    for(int k=i;k<n;k++)
                    {
                        st.insert(x^nums[k]);
                    }
                }
            }
        }
        return st.size();
    }
};