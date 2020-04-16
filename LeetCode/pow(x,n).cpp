class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        double temp=myPow(x,n/2);
        temp*=temp;
        if(n>0){
            double single=x;
            if(n&1)temp*=single;
        }
        else {
            double single=1.0/x;
            if(n&1)temp*=single;
        }
        return temp;
    }
};
