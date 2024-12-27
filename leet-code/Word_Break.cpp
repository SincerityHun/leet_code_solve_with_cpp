#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // DP
        // s[i] 길이가 i 사용했을 때 가능한지 불가능한지.
        int limit = s.size();
        vector<bool> dp(limit + 1, false);
        dp[0] = true;
        int tmp_limit;
        for (int i = 1; i < limit + 1; ++i)
        {
            for (string& word: wordDict){
                tmp_limit = word.size();
                if(i-tmp_limit < 0)
                    continue;
                if (word.compare(s.substr(i - tmp_limit, tmp_limit))==0 && dp[i-tmp_limit]){
                    dp[i] = true;
                    // cout << s.substr(i - tmp_limit, tmp_limit) << endl;
                 break;
                }
            }
        }
        return dp[limit];
    }
};