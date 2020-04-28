#define mod 1000000007

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        if(A==B){
            return ((long long)N * A)%mod;
        }
        
        long long lcm=A*B/gcd(A,B);
        int da=lcm/A,db=lcm/B;
        int cycle=da+db-1;
        
        int req=N/cycle;
        int rem=N%cycle;
          
        long long num=(lcm*req)%mod;
        long long ans;
        int i=1,j=1,cnt=0;
        while(cnt<rem){
            if(A*i <B*j){
                ans=(num+(A*i)%mod)%mod;
                i++;
            }
            else {
                ans=(num+(B*j)%mod)%mod;
                j++;
            }
            cnt++;
        }
        return ans;
    }
};
