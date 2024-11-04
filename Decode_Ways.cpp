#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        // dp[x]까지 갔을 때 해석될 수 있는 최대 가짓수
        // 전에 숫자가 굉장히 중요함
        // x-1의 숫자가 만약에 -> 0,3,4,5,6,7,8,9 와 같다면 뒤에 가짓수가 될 수없음
        // 12: (1,2) (12)
        // 123: (1,2,3), (12,3), (1,23)
        // 127: (1,2,7), (12,7)
        if (s.empty() || s[0] == '0')
            return 0;

        int limit = s.length();
        vector<int> dp(limit + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= limit; ++i)
        {
            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));

            if(oneDigit != 0){
                dp[i] += dp[i - 1];
            }
            if(10 <= twoDigit && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[limit];
    }
};