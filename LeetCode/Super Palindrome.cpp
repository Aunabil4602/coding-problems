long long getA(long long x)
{
    string ok;
    long long temp=x;
    while(temp>0){
        ok+=('0'+(temp%10));
        temp/=10;
    }
    int len=ok.length();
    reverse(ok.begin(),ok.end());
    string half=ok.substr(0,len-1);
    reverse(half.begin(),half.end());
    ok+=half;
    long long ans=0;
    for(auto c:ok)ans=ans*10+(c-'0');
    return ans;
}

long long getB(long long x)
{
    string ok;
    long long temp=x;
    while(temp>0){
        ok+=('0'+temp%10);
        temp/=10;
    }
    reverse(ok.begin(),ok.end());
    string half=ok;
    reverse(half.begin(),half.end());
    ok+=half;
    long long ans=0;
    for(auto c:ok)ans=ans*10+(c-'0');
    return ans;
}

bool isPal(long long x)
{
    string ok;
    long long temp=x;
    while(temp>0){
        ok+=('0'+temp%10);
        temp/=10;
    }
    int i=0,j=ok.length()-1;
    while(i<j){
        if(ok[i]!=ok[j])return 0;
        i++;j--;
    }
    return 1;
    
}

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        
        long long numL=0,numR=0;
        for(auto c:L){
            numL*=10;
            numL+=(c-'0');
        }
        for(auto c:R){
            numR*=10;
            numR+=(c-'0');
        }
        
        numL--;
        int cntA=0,cntB=0;
        long long cur=0;
        
        while(1){
            long long a=getA(cur);
            if(a>(1e9))break;
            long long aa=a*a;
            if(aa>numR)break;
            if(isPal(a) && isPal(aa)){
                cntB+=(aa<=numR);
                cntA+=(aa<=numL);
            }
            cur++;
        }
        
        cur=0;
        while(1){
            long long b=getB(cur);
            if(b>(1e9))break;
            long long bb=b*b;
            if(bb>numR)break;
            if(isPal(b) && isPal(bb)){
                cntB+=(bb<=numR);
                cntA+=(bb<=numL);
            }
            cur++;
        }
        return cntB-cntA;
    }
};
