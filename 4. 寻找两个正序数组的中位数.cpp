#include <stack>
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <math.h>
#include <bitset>
using namespace std;
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int len1 = nums1.size(), len2 = nums2.size();
//        int left = (len1 + len2 + 1) / 2;
//        int right = (len1 + len2 + 2) / 2;
//        return (getKth(nums1, 0, len1-1, nums2, 0, len2-1, left) + getKth(nums1, 0, len1-1, nums2, 0, len2-1, right)) * 0.5;
//    }
//    double getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
//        int len1 = end1 - start1+1;
//        int len2 = end2 - start2+1;
//        if (len1 > len2)return getKth(nums2, start2, end2, nums1, start1, end1, k);
//        if (len1 == 0)return nums2[start2 + k - 1];
//        if (k == 1)return min(nums1[start1], nums2[start2]);
//        int i = start1 + min(len1, k / 2) - 1;
//        int j = start2 + min(len2, k / 2) - 1;
//        if (nums1[i] < nums2[j])return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
//        else return getKth(nums1, start1, end1, nums2, j+1, end2, k - (j -start2+ 1));
//
//    }
//};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)return findMedianSortedArrays(nums2, nums1);
        int iMin = 0, iMax = m;
        while (iMin<=iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;
            if (j != 0 && i != m && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            }
            else if (i != 0 && j != n && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0)maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1)return maxLeft;

                int minRight = 0;
                if (i == m) minRight = nums2[j];//这两行的i,j判断不能跟上面一样，否则[],[2,3]无法通过测试
                else if (j==n)minRight = nums1[i];
                else minRight = min(nums1[i ], nums2[j ]);
                return (maxLeft + minRight) * 0.5;
            }
        }
        return 0.0;
    }
    
};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}