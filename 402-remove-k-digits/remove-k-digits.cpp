class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(k==num.size()) return "0";
        //if()
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>num[i]-'0'){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        
        // Remove leading zeros
        int pos = 0;
        while (pos < result.size() && result[pos] == '0') {
            pos++;
        }
        result = result.substr(pos);
        
        return result.empty() ? "0" : result;
    }
};