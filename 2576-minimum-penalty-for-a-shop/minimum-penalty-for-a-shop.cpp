class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size();
        int total = count(cus.begin(), cus.end(), 'Y');
        int aajtakaaya = 0;
        int ref = INT_MAX;
        int ans = 0;
        for(int i=0;i<=n;i++)
        {
            int penalty = 0;
            penalty+= (i - aajtakaaya);
            penalty+= (total - aajtakaaya);
            if(penalty < ref)
            {
                ref = penalty;
                ans = i;
            }
            if(i == n) break;
            if(cus[i] == 'Y') aajtakaaya++;
        }
        return ans;
    }
};