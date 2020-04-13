#define N 1005
vector<string> s[20];
vector<int> dp[20];

bool check(string a,string b)
{
    int cnt=0;
    int i=0,j=0;
    while(i<a.length() && j<b.length()){
        if(a[i]!=b[j]){
            cnt++;
            i--;
            if(cnt>1)return false;
        }
        i++;
        j++;
    }
    
    return true;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<20;i++){
            s[i].clear();
            dp[i].clear();
        }
        for(auto x:words){
            s[int(x.length())].push_back(x);
            dp[int(x.length())].push_back(1);
        }
        int ans=1;
        for(int len=1;len<16;len++){
            for(int i=0;i<dp[len].size();i++){
                for(int j=0;j<dp[len+1].size();j++){
                    if(check(s[len][i],s[len+1][j])){
                        dp[len+1][j]=max(dp[len+1][j],1+dp[len][i]);
                        ans=max(ans,dp[len+1][j]);
                    }
                }
            }
        }
        
        return ans;
    }
};
