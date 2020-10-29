#include<bits/stdc++.h>

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int mx=0;
        int cur=0;
        for(int i=0;i<seats.size();i++){
            if(!seats[i]){
                cur++;
                mx=max(cur,mx);
            }
            else {
                cur=0;
            }
        }
        
        mx=(mx+1)/2;
        int i=0;
        while(i<seats.size() && !seats[i])i++;
        mx=max(mx,i);
        
        i=seats.size()-1;
        while(i>=0 && !seats[i])i--;
        mx=max(mx,int(seats.size()-i-1));
        
        return mx;
    }
};
