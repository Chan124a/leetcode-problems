class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x ^ y;
        int ans = 0;
        while (c != 0)
        {
            if (c & 1)ans++;
            c = c >> 1;
        }
        return ans;
    }
};