class Solution {
public:
    stack<int> st;

    vector<int> lse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();

        vector<int> left(n);
        for (int i = 0; i < left.size(); i++) {
            while (st.size() > 0 && heights[st.top()] > heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> rse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();

        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> l = lse(heights);
        vector<int> r = rse(heights);
        int carea = 0;
        int ans = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int width = r[i] - l[i] - 1;

            carea = heights[i] * width;
            ans = max(carea, ans);
        }
        return ans;
    }
};