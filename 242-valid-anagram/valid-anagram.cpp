class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> count(26,0);
        for(char ch:s){
            count[ch-'a']++;
        }
        for(char ch:t){
            count[ch-'a']--;
        }
        for(int i=0;i<count.size();i++){
            if(count[i]!=0) return false;
        }
        return true;
    }
};