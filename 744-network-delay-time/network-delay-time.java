class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n+1, Integer.MAX_VALUE));
        Map<Integer, ArrayList<int[]>> graph = new HashMap<>();
        for(var it : times)
        {
            int u = it[0], v = it[1], w = it[2];
            graph.putIfAbsent(u, new ArrayList<>());
            graph.get(u).add( new int [] {v,w});
        }
        PriorityQueue<int []> pq = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        pq.add(new int[]{0, k});
        ans.set(k , 0);

        while(pq.size() > 0)
        {
            int dist = pq.peek()[0];
            int node = pq.poll()[1];
            if(dist > ans.get(node)) continue;

            for(var it : graph.getOrDefault(node, new ArrayList<>()))
            {
                int v = it[0], w = it[1];
                if(dist + w < ans.get(v))
                {
                    ans.set(v, dist+w);
                    pq.add(new int[] {dist + w, v});
                }
            }
        }
        int answer = 0;
        for(int i=1;i<=n;i++)
        {
            if(ans.get(i) == Integer.MAX_VALUE) return -1;
            answer = Math.max(answer, ans.get(i));
        }
        return answer;
    }
}