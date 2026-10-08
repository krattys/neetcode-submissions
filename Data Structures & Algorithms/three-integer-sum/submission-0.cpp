class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            int target = -1 * nums[i];
            while (l < r) {
                if (l == i) {
                    l++;
                    continue;
                }
                if (r == i) {
                    r--;
                    continue;
                }

                if (nums[l] + nums[r] > target) {
                    r--;
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    vector<int> temp;
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    temp.push_back(nums[i]);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                    l++;
                    r--;
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
