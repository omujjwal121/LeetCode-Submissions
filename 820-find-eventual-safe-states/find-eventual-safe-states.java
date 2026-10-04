class Solution {
    Map<Integer, Boolean> vis = new HashMap<>();
    Map<Integer, Boolean> anser = new HashMap<>();
    private boolean check(int curr, Map<Integer, Boolean>inPath, int[][] graph)
    {
        // System.out.println(curr);
        inPath.put(curr, true);
        boolean ans = true;
        for(var it : graph[curr])
        {
            int v = it;
            if(inPath.get(v) != null || (anser.get(v) != null && anser.get(v) == false))
            {
                ans = false;
                break;
            }
            if(ans && vis.get(v) == null)
            {
                vis.put(v, true);
                ans = ans && check(v, inPath, graph);
            }
        }
        inPath.remove(curr);
        anser.put(curr, ans);
        return ans;
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        // boolean ans = true;
        Map<Integer, Boolean> inPath = new HashMap<>();
        for(int i=0;i<graph.length;i++)
        {
            if(vis.get(i) == null)
            {
                vis.put(i, true);
                check(i, inPath, graph);
                // System.out.println("---------------------");
            }
        }
        List<Integer>answer = new ArrayList<>();
        for(int i=0;i<graph.length;i++)
        {
            if(anser.get(i) == null) answer.add(i);
            else if(anser.get(i) == true) answer.add(i);
        }
        return answer;
    }
}