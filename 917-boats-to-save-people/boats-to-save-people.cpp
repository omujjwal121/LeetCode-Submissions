class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int ans = 0;
        sort(p.begin(), p.end());
        int left=0, right = p.size()-1;
        while(left<=right)
        {
            if(p[left]+p[right] <= limit)
            {
                ans++;left++;right--;
            }
            else
            {
                ans++;right--;
            }
        }
        return ans;
    }
};