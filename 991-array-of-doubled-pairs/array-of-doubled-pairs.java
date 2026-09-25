class Solution {
    public boolean canReorderDoubled(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for(int i=0;i<n;i++)
        {
            if(mp.get(arr[i])!=null)
            {
                mp.put(arr[i], mp.get(arr[i])-1);
                if(mp.get(arr[i]) == 0) mp.remove(arr[i]);
            }
            else
            {
                if(arr[i]>=0)mp.put(2*arr[i], mp.getOrDefault(2*arr[i], 0)+1);
                else if(arr[i]%2 == 0) mp.put((arr[i])/2, mp.getOrDefault((arr[i])/2, 0)+1);
                else return false;
            }
        }
        if(mp.size() == 0) return true;
        return false;
    }
}