class Solution {
public:
    int maxDepth(string s) {
        int current=0;
        int maxm=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                current++;
                maxm=max(current,maxm);
            }
            else if(s[i]==')'){
                current--;
            }
        }
        return maxm;
    }
};