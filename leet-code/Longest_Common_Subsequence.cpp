#include <string>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /*
        2D을 저장하는 방법의 Memoization
        dp[i][j] => text[0,i-1]와 text[0,j-1]의 Longest Common Subsequence of substring을 저장함

        dp array을 bottom up방식으로 채울거임

        */
        int len_text1 = text1.size();
        int len_text2 = text2.size();
        int memo[len_text1 + 1][len_text2 + 1];
        memset(memo, 0, sizeof(memo));
        for (int i = 1; i <= len_text1; ++i)
        {
            for (int j = 1; j <= len_text2; ++j)
            {
                if (text1[i-1] == text2[j-1])
                {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                }
                else
                {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }
        return memo[len_text1][len_text2];
    }
};