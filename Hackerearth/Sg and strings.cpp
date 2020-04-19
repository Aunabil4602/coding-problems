#include<bits/stdc++.h>
#define LL long long

using namespace std;


int main()
{
    string a,b;
    cin>>b>>a;
    int n=a.length();
    int m=b.length();
    vector<vector<LL> > dp(n+1,vector<LL>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    LL mod=1000000007;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=mod;
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][m]<<endl;
}
