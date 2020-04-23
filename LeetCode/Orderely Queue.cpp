class Solution { O(n^2) if K!=1 else O(nlogn)
public:
    string orderlyQueue(string S, int K) {
        if(K>1)sort(S.begin(),S.end());
        else {
            int n=S.length();
            string mn=S;
            for(int i=0;i<n;i++){
               string b=S.substr(0,i);
               string f=S.substr(i,n-i);
               f+=b;
                if(mn>f)mn=f;
            }
            S=mn;
        }
        return S;
    }
};
