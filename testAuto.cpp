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
#include <time.h>
#include<map>
//#include <bits/stdc++.h>
using namespace std;
//int entryTime(string s, string keypad) {
//	map<int, int> dp;
//	int row = 1;
//	for (int i = 0; i < keypad.size(); i++)
//	{
//		dp[keypad[i]] = row*10+i%3+1;
//		if (i % 3 == 2)row++;
//	}
//	int result = 0;
//	for (int i =1; i < s.size(); i++)
//	{
//		int lo1 = dp[s[i-1]],lo2 = dp[s[i]];
//		if (lo1 == lo2) continue;
//		int row1 = lo1 / 10, row2 = lo2 / 10;
//		if (abs(row1 - row2) > 1) {
//			result += 2;
//			continue;
//		}
//		int col1 = lo1 % 10, col2 = lo2 % 10;
//		if (abs(col1 - col2) > 1)result += 2;
//		else result += 1;
//	}
//	return result;
//}
//int main() {
//	string s;
//	getline(cin, s);
//	string keypad;
//	getline(cin, keypad);
//	int result = entryTime(s, keypad);
//	std::cout << result << "\n";
//	return 0;
//}


// Complete the MaximumArriveAtSameTime function below.
//class Solver {
//public:
//    int MaximumArriveAtSameTime(vector<double>& speed, vector<double>& location, double destination) {
//        vector<double> time;
//        unordered_map<int, int> loToIndex;
//        //vector<int> tempLo;
//        for (int i = 0; i < speed.size(); i++)
//        {
//            time.push_back((destination - location[i]) / speed[i]);
//            //tempLo.push_back(location[i]);
//            loToIndex[location[i]] = i;
//        }
//        sort(location.begin(), location.end());
//        int ans = 0,temp=1;
//        for (int i = time.size()-1; i >0; i--)
//        {
//            int index1 = loToIndex[location[i]], index2 = loToIndex[location[i - 1]];
//            if (time[index1] > time[index2]) {
//                time[index2] = time[index1];
//                temp++;
//                if (temp > ans)ans = temp;
//            }
//            else
//            {
//                temp =1;
//            }
//        }
//        return ans;
//    }
//};
class Solver {
public:
    int MaximumArriveAtSameTime(vector<double>& speed, vector<double>& location, double destination) {
        //vector<double> time;
        unordered_map<int, int> loToIndex;
        //vector<int> tempLo;
        for (int i = 0; i < speed.size(); i++)
        {
            int temp = (destination - location[i]) / speed[i];
            //tempLo.push_back(location[i]);
            loToIndex[location[i]] = temp;
        }
        sort(location.begin(), location.end());
        int ans = 0, temp = 1;
        for (int i = location.size() - 1; i > 0; i--)
        {
            int index1 = loToIndex[location[i]], index2 = loToIndex[location[i - 1]];
            if (loToIndex[location[i]]>loToIndex[location[i-1]]) {
                loToIndex[location[i - 1]] = loToIndex[location[i]];
                temp++;
                if (temp > ans)ans = temp;
            }
            else
            {
                temp = 1;
            }
        }
        return ans;
    }
};

//  Non-editable part
int main()
{
    int speed_count;
    cin >> speed_count;
    vector<double> speed(speed_count);
    for (int i = 0; i < speed_count; i++) {
        double speed_item;
        cin >> speed[i];
    }
    int location_count = speed_count;
    vector<double> location(location_count);
    for (int i = 0; i < location_count; i++) {
        double location_item;
        cin >> location[i];
    }
    double destination;
    cin >> destination;
    Solver solver;
    int res = solver.MaximumArriveAtSameTime(speed, location, destination);
    std::cout << res << "\n";
    return 0;
}