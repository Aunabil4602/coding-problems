class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0)return false;
        
        int m = matrix[0].size();
        
        int row = 0;
        int l = 0, r = n - 1;
        while(l<r){
            int mid = 1 + (l+r)/2;
            if (matrix[mid][0] > target) {
                r = mid -1;
            } else {
                l = mid;
                row = mid;
            }
        }
        
        l = 0;
        r = m - 1;
        int col = 0;
        while(l<r){
            int mid = 1 + (l+r)/2;
            if(matrix[row][mid]>target){
                r = mid - 1;
            } else {
                l = mid;
                col = mid;
            }
        }
        
        return matrix[row][col]==target;
    }
};
