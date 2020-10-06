class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[10];
        fac[0]=1;
        for(int i=1;i<10;i++)fac[i]=i*fac[i-1];
        vector<int> used(10,0);
        
        string ans="";
        k--;
        for(int i=1;i<=n;i++){
            int times=1+k/fac[(n-i)];
            for(int j=1,cnt=0;j<=n;j++){
                if(!used[j])cnt++;
                if(cnt==times){
                    k-=(times-1)*fac[(n-i)];
                    ans+=(j+'0');
                    used[j]=1;
                    break;
                }
            }
        }
        
        return ans;
    }
};
