class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9 + 7;
        
        // Arrays to store the distance to the next and previous smaller element
        vector<int> left(n), right(n);
        stack<int> s;
        
        // Find previous smaller element (or equal to handle duplicates correctly)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? (i + 1) : (i - s.top());
            s.push(i);
        }
        
        // Clear stack for the next pass
        while (!s.empty()) s.pop();
        
        // Find next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? (n - i) : (s.top() - i);
            s.push(i);
        }
        
        // Calculate the total contribution of each element
        for (int i = 0; i < n; i++) {
            long long contribution = (long long)left[i] * right[i] % mod;
            sum = (sum + (arr[i] * contribution)) % mod;
        }
        
        return sum;
    }
};
