class Solution {
public:
    int findNthDigit(int n) {
        long long ref = 9;
        long long cnt = 1;
        long long temp = 1;
        long long i = 1;
        string end = "9";
        long long prev = 0;
        while(n>ref)
        {
            prev = ref;
            temp = 9* pow(10, i) * (i+1);
            ref+=temp;
            end+='9';
            i++;
        }
        long long start = pow(10, end.length()-1), endd = stoi(end);
        n-=prev;
        long long next = (n/(end.length()))-1;
        start+=next;
        long long rem = n%(end.length());
        if(rem) start++;
        string s = to_string(start);
        long long ans;
        if(rem)  ans = s[rem-1] - '0';
        else ans = s.back() - '0'; 
        return ans;
    }
};