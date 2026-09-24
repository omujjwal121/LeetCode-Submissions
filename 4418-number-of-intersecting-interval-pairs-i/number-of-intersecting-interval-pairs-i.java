class Solution {
    public int countIntersectingIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> {
            if (a[0]!=b[0]) return a[0]-b[0];
            else return b[1] - a[1];
        });
        int ans = 0;
        for(int i=0;i<intervals.length;i++)
        {
            int j=i+1;
            while(j<intervals.length)
            {
                if(intervals[i][1]>=intervals[j][0]) ans++;
                else break;
                j++;
            }
        }
        return ans;
    }
}