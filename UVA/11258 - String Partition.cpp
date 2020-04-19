#include<bits/stdc++.h>
#define N 205
#define LL long long

using namespace std;

LL dp[N];

int main()
{
    memset(dp,0,sizeof (dp));
    int t,n;
    cin>>t;
    LL mx=(1LL << 31)-1;

    while(t--){
        memset(dp,0,sizeof(dp));
        string s;
        cin>>s;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            LL sum=0;
            for(int j=i;j<n;j++){
                sum*=10;
                sum+=(s[j]-'0');
                if(sum>mx)break;
                dp[i]=max<LL>(sum+dp[j+1],dp[i]);
            }
        }
        cout<<dp[0]<<endl;
    }

}
