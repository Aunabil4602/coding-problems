#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        
        int len1=nums1.size();
        int len2=nums2.size();
        if((len1+len2) ==0 )return 0;
        if(len1==0){
            if(len2&1){
                int pos=len2+1;
                pos/=2;
                pos--;
                return nums2[pos];
            }
            else {
                int pos=len2+1;
                pos/=2;
                pos--;
                return (1.0*nums2[pos]+nums2[pos+1])/2;
            }
        }
        int MM=1e7;
        int L=0,R=len1;
        while(L<=R){
            int leftX1=L+(R-L)/2;
            int leftX2=-leftX1+(len1+len2+1)/2;

            int mx1,mx2,mn1,mn2;
            mx1=-(MM);
            mx2=-(MM);
            if(leftX1>0)mx1=nums1[leftX1-1];
            if(leftX2>0)mx2=nums2[leftX2-1];
            mn1=(MM);
            mn2=(MM);
            if(leftX1>0 && leftX1+1<=len1){
                mn1=nums1[leftX1];
            }
            else if(leftX1==0)mn1=nums1[0];
            if(leftX2>0 && leftX2+1<=len2){
                mn2=nums2[leftX2];
            }
            else if(leftX2==0)mn2=nums2[0];
            
            if( mx1<=mn2 && mx2<=mn1 ){
                if((len1+len2)&1){
                    return max(mx1,mx2);
                }
                else {
                    return 1.0*(max(mx1,mx2)+min(mn1,mn2))/2.0;
                }
            }
            else if(mx1<=mn2){
                L=leftX1+1;
            }
            else {
                R=leftX1-1;
            }
        }
        return 0;
    }
};
