class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int b=0;
        int c=0;
        int pos=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')b++;
            else if(s[i]==')')b--;
            else c++;
            if(b<0){
                if(c<=0)return false;
                c--;
                b++;
            }
            if(b==0)pos=i;
        }
        b=0,c=0;
        for(int i=n-1;i>pos;i--){
            if(s[i]=='(')b++;
            else if(s[i]==')')b--;
            else c++;
            if(b>0){
                if(c<=0)return false;
                b--;
                c--;
            }
        }
        return true;
    }
};
