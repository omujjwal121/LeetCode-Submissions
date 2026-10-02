class Solution {
    public class node{
        public int node;
        public double prob;

        public node(int node, double prob)
        {
            this.node = node;
            this.prob = prob;
        }
    }
    public double maxProbability(int n, int[][] edges, double[] succProb, int src, int end) {
        ArrayList<Double> ans = new ArrayList<>(Collections.nCopies(n, 0.0));
        Map<Integer, ArrayList<node>> graph = new HashMap<>();
        for(int i=0;i<edges.length;i++)
        {
            int u = edges[i][0], v = edges[i][1]; double prob = succProb[i];
            graph.putIfAbsent(u, new ArrayList<>());
            graph.putIfAbsent(v, new ArrayList<>());
            graph.get(u).add(new node(v, prob));
            graph.get(v).add(new node(u, prob));
        }
        PriorityQueue<node> pq = new PriorityQueue<>((a,b) -> Double.compare(b.prob , a.prob));
        pq.add(new node(src, 1));
        ans.set(src, 1.0);
        while(pq.size() > 0)
        {
            int nd = pq.peek().node;
            double prob = pq.poll().prob;
            if(prob < ans.get(nd)) continue;
            for (var it : graph.getOrDefault(nd, new ArrayList<>()))
            {
                int next = it.node; double probb = it.prob;
                if(prob * probb > ans.get(next))
                {
                    ans.set(next, prob*probb);
                    pq.add(new node(next , prob * probb));
                }
            }
        }
        return ans.get(end);
    }
}