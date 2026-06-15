class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        // Track the starting index and maximum length of the palindrome found
        int start = 0;
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            // Case 1: Check for odd-length palindromes (centered at i)
            int low = i;
            int high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    start = low;
                    maxLen = high - low + 1;
                }
                low--;
                high++;
            }
            
            // Case 2: Check for even-length palindromes (centered between i and i+1)
            low = i;
            high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    start = low;
                    maxLen = high - low + 1;
                }
                low--;
                high++;
            }
        }
        
        // Return the best substring found
        return s.substr(start, maxLen);
    }
};
