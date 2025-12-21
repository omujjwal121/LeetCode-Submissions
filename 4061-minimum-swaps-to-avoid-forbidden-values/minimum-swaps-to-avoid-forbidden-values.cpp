class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forb) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == forb[i])
            {
                mp[nums[i]].push_back(i);
            }
        }
        vector<pair<pair<int, vector<int>>, int>>v;
        for(auto c:mp) v.push_back({{0,c.second}, c.first});
        for(auto &c:v) c.first.first = c.first.second.size();
        sort(v.begin(), v.end());
        int left = 0, right = v.size()-1;
        int ans = 0;
        while(left<=right)
        {
            if(left==right) break;
            while(v[left].first.first)
            {
                swap(nums[v[left].first.second.back()], nums[v[right].first.second.back()]);
                v[left].first.second.pop_back();
                v[right].first.second.pop_back();
                v[left].first.first--;
                v[right].first.first--;
                if(v[right].first.first == 0) right--;
                ans++;
            }
            left++;
        }
        int y =0;
        if(left==right) y = v[left].first.first;
        if(left == right)
        {
            int val = v[left].second;
            int i=0;
            while(i<n and y)
            {
                if(forb[i]!=val and nums[i]!=val)
                {
                    ans++;
                    y--;
                }
                i++;
            }
        }
        if(y) return -1;
        return ans;
    }
};