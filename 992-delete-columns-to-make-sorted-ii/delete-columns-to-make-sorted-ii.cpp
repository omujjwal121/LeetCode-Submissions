class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        bool f = true;
        while(f)
        {
            f = false;
            set<int>st;
            for(int i=1;i<n;i++)
            {
                if(strs[i]<strs[i-1])
                {
                    f = true;
                    int ind = 0;
                    while(strs[i][ind]>=strs[i-1][ind]) ind++;
                    st.insert(ind);
                }
            }
            for(int i=0;i<n;i++)
            {
                int cnt = 0;
                for(auto c:st)
                {
                    strs[i].erase(strs[i].begin()+c-cnt);
                    cnt++;
                }
            }
            ans+=st.size();
        }
        return ans;
    }
};