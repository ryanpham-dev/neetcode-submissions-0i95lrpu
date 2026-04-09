/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0;
        int r = n;
        int o = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            switch (guess(m)) {
                case 0: {
                    return m;
                }
                case 1: {
                   l = m + 1;
                    break;
                }
                case -1: {
                    r = m - 1;
                    break;
                }
            }
        }
        return o;
    }
};