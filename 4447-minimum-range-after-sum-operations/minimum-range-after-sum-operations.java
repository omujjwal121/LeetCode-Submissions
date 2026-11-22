class Solution {
    public int minRange(int a, int b, int c) {
        int maxi = Math.max(a, Math.max(b,c));
        int mini = Math.min(a, Math.min(b,c));
        return Math.min(a+b+c - maxi - mini, maxi - mini);
    }
}