class Solution {
public:
    int i, j;
    bool check(vector<vector<char>>&grid, int row, int col, int idx, string& word)
    {
        if(idx == word.length()) return true;
        if(row<0 or col<0 or row>=i or col>=j or grid[row][col]!=word[idx] or grid[row][col]=='#') return false;

        char temp = grid[row][col];
        grid[row][col] = '#';
        if(check(grid, row-1, col, idx+1, word)) return true;
        if(check(grid, row+1, col, idx+1, word)) return true;
        if(check(grid, row, col-1, idx+1, word)) return true;
        if(check(grid, row, col+1, idx+1, word)) return true;
        grid[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& grid, string word) {
        i = grid.size();
        j = grid[0].size();

        for(int ii=0;ii<i;ii++)
        {
            for(int jj=0;jj<j;jj++)
            {
                if(grid[ii][jj] == word[0] and check(grid, ii, jj, 0, word)) return true; 
            }
        }
        return false;
    }
};