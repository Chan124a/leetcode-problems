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
#include <unordered_map>
using namespace std;
class Solution {
    int search(vector<int>& arr, int le, int ri) {
        int a = arr[le];
        int left = le, right = ri;
        while (left<right)
        {
            while (arr[right] >= a&& left < right)right--;
            while (arr[left] <= a&& left < right)left++;
            if(left<right)swap(arr[left], arr[right]);
        }
        arr[le] = arr[left];
        arr[left] = a;
        return left;
    }
    void split(vector<int>& arr, int k,int le ,int ri) {
        int p = search(arr, le, ri);
        if (p == k - 1)return;
        else if (p < k - 1)split(arr,k, p + 1, ri);
        else split(arr,k, le, p +1);
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0)return { };
        if (k >= arr.size())return arr;
        split(arr, k, 0, arr.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; i++)ans.push_back(arr[i]);
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().getLeastNumbers(arr, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}