class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n = orders.size();
        priority_queue<vector<int>>buy;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>sell;
        long long ans = 0;
        for(auto c:orders)
        {
            if(c[2]==0)
            {
                if(sell.empty()) buy.push(c);
                else
                {
                    while(sell.size() and sell.top()[0]<=c[0] and c[1]>0)
                    {
                        vector<int>temp = sell.top();
                        int mini=min(temp[1], c[1]);
                        temp[1]-= mini;
                        c[1]-=mini;
                        sell.pop();
                        if(temp[1]) sell.push(temp);
                    }
                    if(c[1]) buy.push(c);
                }
            }
            else
            {
                if(buy.empty()) sell.push(c);
                else
                {
                    while(buy.size() and buy.top()[0]>=c[0] and c[1]>0)
                    {
                        vector<int> temp = buy.top();
                        int mini = min(temp[1], c[1]);
                        temp[1]-=mini;
                        c[1]-=mini;
                        buy.pop();
                        if(temp[1]) buy.push(temp);
                    }
                    if(c[1]) sell.push(c);
                }
            }
        }
        int mod = 1e9+7;
        while(buy.size())
        {
            ans+=buy.top()[1];
            buy.pop();
        }
        while(sell.size())
        {
            ans+=sell.top()[1];
            sell.pop();
        }
        return ans%mod;
    }
};