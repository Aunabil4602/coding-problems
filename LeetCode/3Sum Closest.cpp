#include<bits/stdc++.h> // n^2*log n ... it is possible in only n^2 using 2 pointers

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mn=10000000;          
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                int need=target-(nums[i]+nums[j]);
                int pos=lower_bound(nums.begin()+j+1,nums.end(),need)-nums.begin();
                if(pos>=j+2){
                    if(mn>(abs(target-(nums[i]+nums[j]+nums[pos-1])))){
                        mn=abs(target-(nums[i]+nums[j]+nums[pos-1]));
                        ans=(nums[i]+nums[j]+nums[pos-1]);
                    }
                }
                if(pos<n){
                    if(mn>(abs(target-(nums[i]+nums[j]+nums[pos])))){
                        mn=abs(target-(nums[i]+nums[j]+nums[pos]));
                        ans=(nums[i]+nums[j]+nums[pos]);
                    }
                }
            }    
        }
        return ans;
    }
};
