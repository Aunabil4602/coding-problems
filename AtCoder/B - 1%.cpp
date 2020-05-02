long long total=100,x;
int ans=0;

cin>>x;

while(total<x){
    ans++;
    total=1.01*total;
}
cout<<ans<<endl;
