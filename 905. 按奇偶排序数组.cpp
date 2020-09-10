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
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int left = 0, right = n - 1;
        while (left<right)
        {
            while (A[left] % 2 == 0&&left<right)left++;
            swap(A[left], A[right]);
            while (A[right] % 2 == 1 && left < right)right--;
            swap(A[left], A[right]);
        }
        return A;
    }
};