class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> answer(row, vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int start_row = i-k<0?0:i-k;
                int end_row = i+k<row?i+k:row-1;
                int start_col = j-k<0?0:j-k;
                int end_col = j+k<col?j+k:col-1;
                int ans = 0;
                if(start_col>0)
                {
                    for(int k=start_row;k<=end_row;k++) ans+=mat[k][end_col] - mat[k][start_col-1];
                }
                else
                {
                    for(int k=start_row;k<=end_row;k++) ans+=mat[k][end_col];
                }
                answer[i][j] = ans;
            }

        }
        return answer;
    }
};