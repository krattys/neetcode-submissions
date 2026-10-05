class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeros = 0;
        for (int num: nums) {
            if (num == 0) {
                zeros++;
                continue;
            }
            product *= num;
        }

        int n = nums.size();
        vector<int> res(n);
        
        if (zeros > 1) {
            return res;
        }
        if (zeros == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    res[i] = product;
                }
            }
            return res;
        }

        for (int i = 0; i < n; i++) {
            res[i] = product / nums[i];
        }
        return res;
    }
};
