class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), suff(n, 1);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] * pref[i-1];
        }

        suff[n - 1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i] * suff[i+1];
        }

        // for (int i = 0; i < n; i++) cout << pref[i] << " ";
        // cout << "\n";
        // for (int i = 0; i < n; i++) cout << suff[i] << " ";
        // cout << "\n";

        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) res[i] *= pref[i-1];
            if (i + 1 < n) res[i] *= suff[i+1];
        }

        return res;
    }
};
