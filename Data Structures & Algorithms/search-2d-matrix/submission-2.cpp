class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int l = -1, r = rows * cols;

        while (r > l + 1) {
            int m = (l + r) / 2;
            int cr = m / cols, cc = m % cols;
            if (matrix[cr][cc] <= target) {
                l = m;
            } else {
                r = m;
            }
            // cout << m << " " << cr << " " << cc << " " << l << " " << r << "\n";
        }

        if (l == -1) return false;
        int fr = l / cols, fc = l % cols;
        // cout << "\n" << l << " " << fr << " " << fc << "\n";
        return matrix[fr][fc] == target;
    }
};
