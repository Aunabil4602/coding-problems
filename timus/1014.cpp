#include<bits/stdc++.h>
#define N 105
#define LL long long


using namespace std;

int n;

int main()
{
    cin>>n;
    
    if(n==1){
        cout<<n<<endl;
        return 0;
    }
    if(n==0){
        cout<<10<<endl;
        return 0;
    }
    
    string s;
    for(int i=9;i>1;i--){
        int x=i;
        while(n%x==0){
            s+=('0'+x);
            n/=x;
        }
    }
    sort(s.begin(),s.end());
    if(n==1)cout<<s<<endl;
    else cout<<-1<<endl;
}
