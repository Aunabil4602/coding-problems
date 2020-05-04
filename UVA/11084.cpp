//bitmask, complexity O(s.length*divisor*10)

#include<bits/stdc++.h>
#define N 1030
#define D 10005
#define LL long long


using namespace std;

int dp[N][D];
int d;
string s;

int value(int bit,int rem)
{
    if(dp[bit][rem]!=-1)return dp[bit][rem];
    dp[bit][rem]=0;
    bool ok=true;
    for(int i=0;i<s.length();i++){
        if(bit&(1<<i))continue;
        ok=false;
        dp[bit][rem]+=value(bit|(1<<i),(rem*10+(s[i]-'0'))%d);
    }
    if(ok)dp[bit][rem]=(rem==0);
    return dp[bit][rem];
}

int main()
{
    int t;
    cin>>t;
    
    int fac[11];
    fac[0]=1;
    for(int i=1;i<=10;i++)fac[i]=i*fac[i-1];
    
    while(t--){
        cin>>s>>d;
        for(int i=0;i<N;i++)for(int j=0;j<d+5;j++)dp[i][j]=-1;
        
        int ans=value(0,0); 
        map<int,int> cnt;
        for(auto x:s)cnt[x-'0']++;
        for(int i=0;i<26;i++)ans/=fac[cnt[i]];
        
        cout<<ans<<endl;
    }
}
