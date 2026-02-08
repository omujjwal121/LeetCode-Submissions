class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        for(int i=0;i<nums.size();i++)
        {
            long long c = nums[i];
            if(st.empty()) st.push(c);
            else if(st.top() == c)
            {
                while(st.size() and st.top()==c)
                {
                    c*=2;
                    st.pop();
                }
                st.push(c);
            }
            else st.push(c);
        }
        vector<long long> ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};