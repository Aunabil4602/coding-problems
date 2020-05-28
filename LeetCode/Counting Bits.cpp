class Solution { //O(n)
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        int dp=1;
        for(int i=1;i<=num;i++){
            if(i==dp*2)dp*=2;
            ans[i]=1+ans[i-dp];
        }
        return ans;
    }
};
