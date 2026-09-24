class Solution {
    public long countIntersectingIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b)->{
            if(a[0]!=b[0]) return a[0]-b[0];
            else return a[1]-b[1];
        });
        long ans = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> {
            return a[0]-b[0];
        });
        for(int i=0;i<intervals.length;i++)
        {
            while(pq.size()>0 && pq.peek()[0]<intervals[i][0])
            {
                ans+=i-1 - pq.peek()[1];
                pq.poll();
            }
            pq.add(new int[]{intervals[i][1], i});
        }
        while(pq.size()>0)
        {
            ans+=intervals.length-1 - pq.peek()[1];
            pq.poll();
        }
        return ans;
    }
}