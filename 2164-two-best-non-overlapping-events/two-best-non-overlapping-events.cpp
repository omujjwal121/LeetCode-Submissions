class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int>v(n);
        int maxi = events.back()[2];
        for(int i = n-1;i>=0;i--)
        {
            maxi = max(maxi, events[i][2]);
            v[i] = maxi;
        }
        int ans = 0;
        for(int i = 0; i<n;i++)
        {
            int a = events[i][2];
            int end = events[i][1];
            
            int left = i+1, right = n-1;
            int mid = (right + left)/2;
            while(left <= right)
            {
                mid = (right + left)/2;
                if(events[mid][0]>end and events[mid-1][0]<=end) break;
                else if(events[mid][0]>end and events[mid-1][0]>end)right = mid-1;
                else left = mid+1;
            }
            if(mid<n and left<=right) a+=v[mid];
            ans = max(ans, a);
        }
        return ans;
    }
};