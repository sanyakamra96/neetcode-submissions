class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = piles[0];

        for (int pile : piles) {
            if (pile > maxPile) {
                maxPile = pile;
            }
        }
        if(h == piles.size()){
            return maxPile;
        }

        int left = 1;
        int right = maxPile;

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long total = 0;

            for (int pile : piles) {
                int hours = pile / mid;

                if (pile % mid != 0) {
                    hours++;
                }

                total += hours;
            }

            if (total <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};