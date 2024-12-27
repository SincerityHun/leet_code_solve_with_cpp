#include <string>
#include <regex>

using namespace std;

/*
오답노트
-> 절반의 값이 #으로 이루어진거라면 dp의 결과를 더할 때 이를 절반으로 나누어 더하는 것도 좋은 방법이다.

*/
class Solution
{
public:
    int countSubstrings(string s)
    {
        // 조기 종료 조건 확인
        if (s.length() == 1)
            return 1;
        // 정의
        s = regex_replace(s, regex(""), "#");
        int limit = s.length();
        vector<int> dp(limit, 0); // x에서 pelindrome 반지름 길이, 0이면 없는거임
        int center = 0;           // 지금까지 가장 먼 범위까지 펠린드롬을 가지고 있는 좌표
        int right = 0;

        for (int i = 0; i < limit; ++i)
        {
            // 이미 계산된 거라면 DP로 확인하기
            if (i < right)
            {
                dp[i] = min(right - i, dp[2 * center - i]);
            }
            // 그 값을 너머 반지름 계산하기
            while (i + dp[i] + 1 < limit && i - dp[i] - 1 >= 0 && s[i + dp[i] + 1] == s[i - dp[i] - 1])
            {
                ++dp[i];
            }
            // 기존 값을 뛰어넘었다면 업데이트하기
            if (i + dp[i] > right)
            {
                center = i;
                right = i + dp[i];
            }
        }
        // 값을 구하기
        int result = 0;
        for (int i = 0; i < limit; ++i)
        {
            result += (dp[i] + 1)/2;
        }
        return result;
    }
};