class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long long a=abs(divisor);
        unsigned long long b=abs(dividend);
        long long ans=0;
        int pos1=(dividend>=0);
        int pos2=(divisor>=0);
        for(int i=32;i>=0;i--){
            if((a<<i)<=b){
                b-=(a<<i);
                ans+=((long long)1<<i);
            }
        }
        if(ans>=((long long)1<<31) && (pos1==pos2))ans=((long long)(1<<31)-1);
        return ans*(pos1!=pos2 ? -1:1);
    }
};
