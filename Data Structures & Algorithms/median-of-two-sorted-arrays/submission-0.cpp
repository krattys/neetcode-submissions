class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &A = nums1;
        vector<int> &B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0, r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            // cout << i << " " << j << " " << l << " " << r << "\n";
            
            int ALeft = i > 0 ? A[i-1] : INT_MIN;
            int ARight = i < A.size() ? A[i] : INT_MAX;

            int BLeft = j > 0 ? B[j-1] : INT_MIN;
            int BRight = j < B.size() ? B[j] : INT_MAX;

            // cout << ALeft << " " << ARight << "\n" << BLeft << " " << BRight << "\n";

            if (ALeft <= BRight && BLeft <= ARight) {
                if (total % 2) {
                    return max(ALeft, BLeft);
                }
                return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }

            if (ALeft > BRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};
