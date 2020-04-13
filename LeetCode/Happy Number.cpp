class Solution {
public:
    bool isHappy(int n) {
        map<int,int> dp;
        while(!dp[n]){
            dp[n]=1;
            int nxt=0;
            while(n>0){
                int cur=n%10;
                cur=cur*cur;
                nxt+=cur;
                n/=10;
            }
            n=nxt;
        }
        return (n==1)? true:false;
    }
};
