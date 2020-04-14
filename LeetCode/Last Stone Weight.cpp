#include<bits/stdc++.h>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> arr;
        for(auto x:stones){
            arr.insert(x);
        }
        while(arr.size()>1){
            int big=*arr.rbegin();
            arr.erase(--arr.end());
            int small=*arr.rbegin();
            arr.erase(--arr.end());
            int dif=big-small;
            if(dif>0)arr.insert(dif);
        }
        return *arr.begin();
    }
};
