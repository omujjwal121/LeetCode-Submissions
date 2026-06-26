class Solution {
public:
    int maxDistance(string moves) {
        int hor=0, ver=0, blank = 0;
        for(auto c:moves)
        {
            if(c == 'L') hor--;
            else if(c == 'R') hor++;
            else if(c == 'U') ver++;
            else if(c == 'D') ver--;
            else blank++;
        }
        return abs(hor)+abs(ver)+blank;
    }
};