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
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;//list中没有要查找单词
        unordered_set<string> upTodown({ beginWord });
        unordered_set<string> downToup({ endWord });
        int word_size = beginWord.size();
        int list_size = wordList.size();
        vector<bool> flag(list_size, false);
        int res = 2;
        while (!upTodown.empty())
        {
            unordered_set<string> next;
            for (auto& word : upTodown) {
                for (int i = 0; i < list_size; i++)
                {
                    int count = 0;
                    for (int j = 0; j < word_size; j++)
                    {
                        if (word[j] != wordList[i][j])count++;
                        if (count > 1)break;
                    }
                    if (count == 1) {
                        if (downToup.count(wordList[i]) != 0)return res;
                        if (flag[i] == false)next.insert(wordList[i]);
                        flag[i] = 1;
                    }
                }
            }
            res++;
            upTodown = next;
            if (upTodown.size() > downToup.size())swap(upTodown, downToup);
        }
        return 0;
    }
};
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string>wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    int ans = Solution().ladderLength(beginWord, endWord, wordList);
}