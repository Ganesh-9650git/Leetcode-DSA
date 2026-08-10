#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> map; // Pairs element with its next greater element
        
        // 1. Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            
            // Pop smaller elements from the stack
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            
            // If stack is empty, no greater element exists to the right
            if (st.empty()) {
                map[current] = -1;
            } else {
                map[current] = st.top();
            }
            
            // Push current element for future iterations
            st.push(current);
        }
        
        // 2. Build the result for nums1 using our precalculated map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(map[num]);
        }
        
        return result;
    }
};
