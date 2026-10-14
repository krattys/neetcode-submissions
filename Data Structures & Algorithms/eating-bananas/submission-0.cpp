class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end());
        while (r > l + 1) {
            int m = (l + r) / 2;
            int timeTaken = 0;
            for (int pile: piles) {
                timeTaken += (pile / m) + (pile % m == 0 ? 0 : 1);
            }

            if (timeTaken <= h) {
                r = m;
            } else {
                l = m;
            }
        }

        return r;
    }
};
