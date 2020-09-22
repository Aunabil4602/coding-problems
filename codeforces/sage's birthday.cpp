#include<bits/stdc++.h>

using namespace std;

#define N 100005
int arr[N];
int ans[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int half=n/2;
    for(int i=0,pos=1;i<half;i++,pos+=2){
        ans[pos]=arr[i];
    }

    for(int i=half,pos=0;i<n;i++,pos+=2){
        ans[pos]=arr[i];
    }

    int cnt=0;
    for(int i=1;i+1<n;i++){
        if(ans[i]<ans[i-1] && ans[i]<ans[i+1])cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
