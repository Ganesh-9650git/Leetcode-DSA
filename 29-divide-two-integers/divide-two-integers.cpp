class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend < 0 && divisor > 0)
            sign = false;
        long long dn = abs((long long)dividend);
        long long dr = abs((long long)divisor);
        long long quotient = 0;
        while (dn >= dr) {
            int count = 0;
            while (dn >=  (dr << (count + 1))) {
                count++;
            }
            quotient = quotient + (1 << count);
            dn=dn-(dr<<count);
        }
        if(quotient== (1<<31) && sign==true) return INT_MAX;
        if(quotient== (1<<31) && sign==false) return INT_MIN;
        return sign ? quotient:(-quotient);
    }
};