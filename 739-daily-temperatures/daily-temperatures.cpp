class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>ans(n);
        stack<pair<int, int>>st;

        for(int i=n-1;i>=0;i--)
        {
            while(st.size() and st.top().first <= t[i]) st.pop();
            if(st.size()==0) ans[i] = 0;
            else ans[i] = st.top().second - i;
            st.push({t[i], i});
        }

        return ans;
    }
};