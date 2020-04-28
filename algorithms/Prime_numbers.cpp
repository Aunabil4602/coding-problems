int isPrime[N];
memset(isPrime,1,sizeof isPrime);
vector<int> primes;
primes.push_back(2);
for(int i=4;i<N;i+=2)isPrime[i]=0;

for(long long i=3;i<N;i+=2){
    if(isPrime[i]){
        primes.push_back(i);
        for(long long j=i*i;j<N;j+=i){
            isPrime[j]=0;
        }
    }
}
        
