class Solution {
 public :
     string makeLargestSpecial ( string S) {
         cout<<"-> "<<S<<endl;
         int n=S.length();
         if(n==0)return "";
         int cnt=0;
         int start=0;
         vector<string> arr;
         for(int i=0;i<n;i++){
             if(S[i]=='1')cnt++;
             else cnt--;
             if(!cnt){
                 string mid;
                 if(start+1 < i-1)mid=makeLargestSpecial(S.substr(start+1,i-start-1));
                 string res="1"+mid+"0";
                 arr.push_back(res);
                 start=i+1;
             }
         }
         sort(arr.begin(),arr.end());
         reverse(arr.begin(),arr.end());
         string ans;
         for(auto x:arr)ans+=x;
         return ans;
    }
};
