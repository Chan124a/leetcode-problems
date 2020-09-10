#include <stack>
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <climits>
using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int sum;
        bool flag=false;
        int max_fu=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0&&!flag){
                flag=true;
                sum=0;
            }
            if(flag){
                sum+=nums[i];
                if(sum>max) max=sum;
                if(sum<=0) sum=0;
            }
            if(nums[i]<0&&nums[i]>max_fu) max_fu=nums[i];
        }
        if(!flag) return max_fu;
        else return max;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}