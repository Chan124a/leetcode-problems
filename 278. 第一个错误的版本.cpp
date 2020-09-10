 
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 0, right = n;
        while (left < right)
        {
            long long  mid = ((long long int)left + right) / 2;
            if (!isBadVersion(mid))left = mid + 1;
            else right = mid;
        }
        return left;
    }
};