class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        vector<vector<int>>ans;
        int n = s1.size(), m=s2.size();
        int i=0,j=0;
        while(i<n and j<m)
        {
            int val1, val2;
            val1 = i>=n?0:s1[i][1];
            val2 = j>=m?0:s2[j][1];
            ans.push_back({min(s1[i][0], s2[j][0]), val1+val2});
            if(s1[i][0] == s2[j][0])
            {
                i++;j++;
            }
            else if(s1[i][0] < s2[j][0]) i++;
            else j++;
        }
        while(i<n)
        {
            ans.push_back(s1[i]);i++;
        }
        while(j<m)
        {
            ans.push_back(s2[j]);j++;
        }
        return ans;
    }
};