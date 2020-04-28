class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)return 0;
        while(num%2==0)num/=2;
        while(num%3==0)num/=3;
        while(num%5==0)num/=5;
        return num==1;
    }
};     


class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0,p3=0,p5=0;
        
        vector<long long> arr(1,1);
        while(arr.size()<n){
            long long a2=2*arr[p2];
            long long a3=3*arr[p3];
            long long a5=5*arr[p5];
            if(a2<=a3 && a2<=a5){
                arr.push_back(a2);
                p2++;
                if(a3==a2)p3++;
                if(a5==a2)p5++;
            }
            else if(a3<=a2 && a3<=a5){
                arr.push_back(a3);
                p3++;
                if(a2==a3)p2++;
                if(a5==a3)p5++;
            }
            else {
                arr.push_back(a5);
                p5++;
                if(a2==a5)p2++;
                if(a3==a5)p3++;
            }
        }
        return arr.back();
    }
};
