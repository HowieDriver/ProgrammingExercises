class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int start_x=0, start_y=0, end_x=matrix.size()-1, end_y=matrix[0].size()-1;
        int i=0, j=0;
        vector<int> ans;
        vector<vector<int> > used = matrix;
        for(int t=0; t<matrix.size(); ++t) {
            used[t].assign(matrix[0].size(), 0);
        }
        while(start_x<=end_x && start_y<=end_y) {
            for(j=start_y; j<=end_y; j++) {
                if(!used[start_x][j]) {
                    ans.push_back(matrix[start_x][j]);
                    used[start_x][j]=1;
                }
                
            }
            for(i=start_x; i<=end_x; i++) {
                if(!used[i][end_y]) {
                    ans.push_back(matrix[i][end_y]);
                    used[i][end_y]=1;
                }
            }
            
            for(j=end_y; j>=start_y; j--) {
                if(!used[end_x][j]) {
                    ans.push_back(matrix[end_x][j]);
                    used[end_x][j]=1;
                }
            }
            for(i=end_x; i>=start_x; i--) {
                if(!used[i][start_y]) {
                    ans.push_back(matrix[i][start_y]);
                    used[i][start_y]=1;
                }
            }
            start_x++;
            start_y++;
            end_x--;
            end_y--;
        }
        return ans;
    }
};
