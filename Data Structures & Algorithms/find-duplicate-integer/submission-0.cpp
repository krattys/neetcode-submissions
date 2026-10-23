class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> count(n);

        for (int num: nums) {
            if (count[num]) {
                return num;
            }
            count[num]++;
        }

        return 0;
    }
};
