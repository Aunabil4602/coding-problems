#include<bits/stdc++.h>  // O(nlogn + n)
#define N 200005
#define LL long long

using namespace std;

pair<LL,LL> ab[N];
int n,t;

bool custom(pair<LL,LL> x, pair<LL,LL> y){
    return (x.first>y.first);
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ab[i].first;
        }

        for(int i=0;i<n;i++){
            cin>>ab[i].second;
        }

        sort(ab,ab+n,custom);

        long long mn=1e10;
        long long sum=0;

        for(int i=0;i<n;i++){
            mn=min(mn,max(ab[i].first,sum));
            sum+=ab[i].second;
        }
        mn=min(mn,sum);
        cout<<mn<<endl;
    }
}
