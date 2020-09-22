#include<bits/stdc++.h>

using namespace std;
#define N 105

int main()
{
    int n,t,x,val;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int a=0,b=0,c=1;
        int cnta=0,cntb=0,cntc=0;
        for(int i=0;i<n;i++){
            cin>>val;
            if (val>x){
                a+=(val-x);
                c=0;
                cnta++;
            }
            else if (val<x){
                b+=(x-val);
                c=0;
                cntb++;
            }
            else cntc++;
        }

        if (c==1){
            cout<<"0"<<endl;
        }
        else {
            if(a==b || cntc>0)cout<<"1"<<endl;
            else cout<<"2"<<endl;
        }
    }
}
