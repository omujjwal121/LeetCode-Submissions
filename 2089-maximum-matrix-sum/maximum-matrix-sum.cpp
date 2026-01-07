class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long total=0;
        int neg = 0;
        int zero=0;
        int max_neg = INT_MAX;
        for(auto c: matrix)
        {
            for(auto d: c)
            {
                total+=abs(d);
                if(d==0) zero++;
                if(d<0)
                {
                    neg++;
                }
                max_neg = min(max_neg, abs(d));
            }
        }
        if(neg%2==0 or zero) return total;
        return total-max_neg-max_neg;
    }
};