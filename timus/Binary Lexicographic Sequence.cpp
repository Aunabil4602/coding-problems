#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 45;

LL dp[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<N;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    
    LL n=6,k;
    cin>>n>>k;

    string s;
    
    if(k>(dp[n][1]+dp[n][0])){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=n;i>0;i--){
        if(k<=dp[i][0]){
            s+='0';
        }else {
            s+='1';
            k-=dp[i][0];
        }
    }
    
    cout<<s<<endl;
    
    return 0;
}
