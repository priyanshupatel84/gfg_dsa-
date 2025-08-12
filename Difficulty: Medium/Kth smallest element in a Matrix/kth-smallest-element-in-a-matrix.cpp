class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        vector<int> v;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            v.push_back(matrix[i][j]);
        }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};
