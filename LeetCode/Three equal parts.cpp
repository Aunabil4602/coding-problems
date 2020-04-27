class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n=A.size();
        int cnt=0;
        for(auto x:A){
            cnt+=x;
        }
        vector<int> ans(2,-1);
        if(cnt%3 !=0)return ans;
        if(!cnt){
            ans[0]=0;
            ans[1]=2;
            return ans;
        }
        
        int ones[cnt+1],zeros[n+1];
        int cur=1;
        memset(zeros,0,sizeof zeros);
        for(int i=0;i<n;i++){
            if(A[i])ones[cur++]=i;
            zeros[i]=(A[i]==0);
            if(i>1)zeros[i]+=zeros[i-1];
        }
        
        int tri=cnt/3;
        int req=n-ones[cnt]-1;
        cout<<req<<endl;
        
        if(zeros[ones[tri+1]]-zeros[ones[tri]] < req)return ans;
        if(zeros[ones[tri*2+1]]-zeros[ones[tri*2]] < req)return ans;
        
        string s[3];
        for(int i=0;i<3;i++){
            for(int j=ones[tri*i+1];j<=ones[tri*(i+1)];j++)s[i]+=('0'+A[j]);    
        }
        if(s[0]!=s[1] || s[1]!=s[2])return ans;
        
        ans[0]=ones[tri]+req;
        ans[1]=ones[tri*2]+req+1;
        return ans;
    }
};
