class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = 0;
            } else {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n - 1;
            } else {
                right[i] = st.top() - 1;
            }
            st.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int curr = (right[i] - left[i] + 1) * heights[i];
            res = max(res, curr);
        }

        // for (int i: left) cout << i << " ";
        // cout << "\n";
        // for (int i: right) cout << i << " ";
        // cout << "\n";

        return res;
    }
};
