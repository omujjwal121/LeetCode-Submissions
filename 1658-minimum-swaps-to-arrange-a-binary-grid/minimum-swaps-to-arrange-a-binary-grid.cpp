class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>last;
        for(int i=0;i<n;i++)
        {
            vector<int>temp = grid[i];
            int ind = n-1;
            while(ind>=0 and grid[i][ind] == 0) ind--;
            last.push_back(ind);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(last[i]>i)
            {
                int ind = i+1;
                while(ind<n and last[ind]>i) ind++;
                if(ind == n) return -1;
                ans+=ind-i;
                for(int j=ind;j>=i+1;j--) swap(last[j], last[j-1]);
            }
        }
        return ans;
    }
};