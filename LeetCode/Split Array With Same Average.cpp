class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int total=0;
        int n=A.size();
        if(n==0)return false;
        for(auto x:A)total+=x;
        
        unordered_map<int,int> dp1[1+n/2],dp2[1+(n+1)/2];
        int half=n/2;
        int tt=(1<<half);
        while(tt--){
            int cnt=0;
            int sum=0;
            for(int i=0;i<half;i++){
                if(tt&(1<<i)){
                    cnt++;
                    sum+=A[i];
                }
            }
            dp1[cnt][sum]=1;
        }
        
        int other=n-half;
        tt=(1<<other);
        while(tt--){
            int cnt=0;
            int sum=0;
            for(int i=0;i<other;i++){
                if(tt&(1<<i)){
                    cnt++;
                    sum+=A[i+half];
                }
            }
            dp2[cnt][sum]=1;
        }
        for(int i=1;i<=n/2;i++){
            if((total*i)%n==0){
                int sum=total*i/n;
                for(int k=0;k<=i;k++){
                    for(auto x:dp1[k]){
                        if(dp2[i-k].count(sum-x.first)>0){
                           return 1;
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
