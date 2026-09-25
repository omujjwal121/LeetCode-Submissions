class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        if(n%2 == 1) return (new int[0]);
        Arrays.sort(changed);
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int[] ans = new int[n];
        int j = 0;
        for(int i=0;i<n;i++)
        {
            if(mp.get(changed[i])!=null)
            {
                mp.put(changed[i], mp.get(changed[i])-1);
                if(mp.get(changed[i]) == 0) mp.remove(changed[i]);
            }
            else {
                mp.put((changed[i])*2, mp.getOrDefault((changed[i])*2, 0) + 1);
                ans[j] = changed[i];
                j++;
            }
        }
        if(mp.size() == 0)
        {
            int [] answer = new int[n/2];
            for(int i=0;i<n/2;i++)
            {
                answer[i] = ans[i];
            }
            return answer;
        }
        return (new int [0]);
    }
}