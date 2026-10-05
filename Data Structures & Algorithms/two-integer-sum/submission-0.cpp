class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> res;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};
