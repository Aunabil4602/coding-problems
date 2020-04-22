/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim=binaryMatrix.dimensions();
        int n=dim[0];
        int m=dim[1];
        int mn=m;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            int ans=m;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(binaryMatrix.get(i,mid)){
                    ans=mid;
                    r=mid-1;
                }
                else {
                    l=mid+1;
                }
            }
            mn=min(ans,mn);
        }
        return (mn==m) ? (-1) : mn;
    }
};
