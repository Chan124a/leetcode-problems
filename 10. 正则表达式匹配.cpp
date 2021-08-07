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
#include <set>
#include <unordered_map>
using namespace std;

////ǰ��̬�滮
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int lens = s.size(), lenp = p.size();
//        //dp[0][0]��ʾs����Ϊ0��p����Ϊ0�������dp[i][j]��ʾs[0,i]��ע�⣺������λ��i,�±�i��ʾ����λ�ã���p[0,j]�Ƿ�ƥ��
//        vector<vector<bool>> dp(lens+1, vector<bool>(lenp+1));
//        for (int i = 0; i <= lens; i++)
//        {
//            for (int j = 0; j <= lenp; j++) {
//                //��s��pΪ�մ�ʱ����Ȼ��ƥ���
//                if (i == 0 && j == 0) {
//                    dp[i][j] = true;
//                    continue;
//                }
//                //�߽���������j=0��i=1,2,3,4,...ʱ������ģʽ��pΪ�մ������Բ�ƥ�䡣
//                //��i=0��j=1ʱ���ַ���sΪ�գ�ƥ�䴮pֻ��һ���ַ�����ȻҲ��ƥ��
//                if (j == 0||(i==0&&j==1)) {
//                    dp[i][j] = false;
//                    continue;
//                }
//                //i=0��ʾ�ַ���sΪ�գ���ʱƥ�䴮p����*���Ա�ʾû��ƥ�䣬����p���ǿ�����մ�sƥ���
//                if (i == 0) {
//                    if (p[j - 1] == '*')dp[i][j] = dp[i][j - 2];
//                    else dp[i][j] = false;
//                    continue;
//                }
//                //���ַ���ȡ�����p��Ӧ�ַ�Ϊ'.'�������ַ���s��ģʽ��pǰһλ�Ƿ�ƥ�伴��
//                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                //��p��Ӧ�ַ�Ϊ��*��,Ҫ���Ǹ������
//                else if (p[j - 1] == '*') {
//                    //����*��ǰ����ַ����ַ���sƥ�䣬���ߡ�*��ǰ����ַ�Ϊ��.������*����ǰ����ַ�����ƥ��ģʽ��s��1λ�ַ�����0λ�ַ�
//                    //��ƥ��1���ַ��������ԳԵ�һ���ַ���������sǰһλ�ַ��Ƿ�ƥ��
//                    //��ƥ��0���ַ�������*���Ա�ʾ0��ƥ�䣬����ģʽ��p��ָ����ǰ����������
//                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
//                        dp[i][j] = dp[i - 1][j] | dp[i][j-2];
//                    }
//                    else dp[i][j] = dp[i][j - 2];
//                }
//                else dp[i][j] = false;
//            }
//        }
//        return dp[lens][lenp];
//    }
//};

//����̬�滮
class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1));
        for (int i = lens; i>=0; i--)
        {
            for (int j = lenp; j >=0; j--) {
                if (i == lens && j == lenp) {
                    dp[i][j] = true;
                    continue;
                }
                if (j == lenp || (i == lens && j == lenp - 1)) {
                    dp[i][j] = false;
                    continue;
                }
                if (i == lens) {
                    if (j < lenp - 1 && p[j + 1] == '*')dp[i][j] = dp[i][j + 2];
                    else dp[i][j] = false;
                    continue;
                }
                if (s[i] == p[j] || p[j] == '.') {
                    if (j + 1 < lenp && p[j + 1] == '*')dp[i][j] = dp[i + 1][j] | dp[i][j + 2];
                    else dp[i][j] = dp[i + 1][j + 1];
                }
                else if (j + 1 < lenp && p[j + 1] == '*')dp[i][j] = dp[i][j + 2];
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}