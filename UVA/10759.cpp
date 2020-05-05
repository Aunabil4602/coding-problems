// dp for finding the sums for different premutations of dices.

#include<bits/stdc++.h>
#define N 25
#define LL long long


using namespace std;

LL total=150;
LL dp[150+1][N];
LL lower[N];

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int main()
{
    memset(dp,0,sizeof dp);
    
    dp[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=total;j>=1;j--){
            for(int k=1;k<=6;k++){
                if((j-k)>=0)dp[j][i]+=dp[j-k][i-1];
            }
        }
    }
    
    for(int i=1;i<N;i++){
        for(int j=1;j<=total;j++)dp[j][i]+=dp[j-1][i];
    }

    lower[0]=1;
    for(int i=1;i<=24;i++)lower[i]=6*lower[i-1];

    int n,x;
    while(cin>>n>>x && (n+x)){
        
        LL nu=dp[total][n];
        if(x>0)nu-=dp[x-1][n];
        
        LL de=lower[n];
        LL ans=gcd(nu,de);

        nu/=ans;
        de/=ans;
        cout<<nu;
        if(de!=1)cout<<"/"<<de;
        cout<<endl;
        
    }
}
