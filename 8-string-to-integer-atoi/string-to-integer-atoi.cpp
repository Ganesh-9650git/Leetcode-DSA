class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++; 
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0'); 

            // Check overflow early to avoid long overflow
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};
