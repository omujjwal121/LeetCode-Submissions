class Solution {
    Map<Integer, Boolean> vis = new HashMap<>();
    private boolean check(int curr, Map<Integer, Boolean> inPath, Map<Integer, ArrayList<Integer>> graph)
    {
        inPath.put(curr, true);
        boolean temp = true;
        for(var it : graph.getOrDefault(curr, new ArrayList<>()))
        {
            int v = it;
            if(inPath.get(v) != null)
            {
                temp = false; break;
            }
            if(temp && vis.get(v)==null)
            {
                vis.put(it, true);
                temp = temp && check(it, inPath, graph);
            }
        }
        inPath.remove(curr);
        return temp;
    }
    public boolean canFinish(int n, int[][] pre) {
        // vis.clear();
        Map<Integer, ArrayList<Integer>> graph = new HashMap<>();
        for(var it : pre)
        {
            int u = it[0], v = it[1];
            graph.putIfAbsent(u, new ArrayList<>());
            graph.get(u).add(v);
        }
        // System.out.println(graph);
        boolean ans = true;
        Map<Integer, Boolean> inPath = new HashMap<>();
        for(int i=0;i<n;i++)
        {
            if(ans && vis.get(i)==null) {
                vis.put(i, true);
                // inPath.clear();
                ans = ans && check(i, inPath, graph);
            }
        }
        return ans;
    }
}