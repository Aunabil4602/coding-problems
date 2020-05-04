//bitmask 

#include<bits/stdc++.h>
#define N 40000
#define LL long long


using namespace std;

int dp[N];
int n;
int arr[20];

int value(int bit)
{
    if(dp[bit]!=-1)return dp[bit];
    dp[bit]=0;

    for(int i=0;i<n;i++){
        if(bit&(1<<i))continue;
        for(int j=i+1;j<n;j++){
            if(bit&(1<<j))continue;
            for(int k=j+1;k<n;k++){
                if(bit&(1<<k))continue;
                if(arr[i]+arr[j]+arr[k] >=20){
                    dp[bit]=max(1+value(bit|(1<<i)|(1<<j)|(1<<k)),dp[bit]);
                }
            }
        }
    }
    return dp[bit];
}

int main()
{
    int cs=1;
    while(cin>>n && n){
        for(int i=0;i<n;i++)cin>>arr[i];
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<cs<<": "<<value(0)<<endl;
        cs++;
    }
}

