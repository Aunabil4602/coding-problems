#include <bits/stdc++.h>
 
using namespace std;
 
long long arr[100005];
long long dis[100005];
int n;
 
int main()
{   
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        
        long long ans = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            
        }
        sort(arr,arr+n);

        for(int i=1;i<n;i++) {
            dis[i-1] = arr[i] - arr[i-1];
            ans+=dis[i-1];
        }
        
        long long neg =0;
        for(int i=1;i<n;i++) {
            neg+= dis[i-1]*(n-i)*(i);
        }
        
        cout<<(ans-neg)<<endl;
    }
    
    return 0;
}
