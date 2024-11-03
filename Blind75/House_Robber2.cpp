#include <vector>
#include <cstring>

using namespace std;

/*
그냥 DP 2번이면 가능..!
*/
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int limits = nums.size();
        int memo[limits];
        memset(memo, 0, sizeof(memo));

        if (limits == 1)
            return nums[0];
        // 1번째 DP: 1번쨰꺼를 선택 안 하는 경우
        // 초기 설정
        memo[0] = 0;

        memo[1] = nums[1];

        for (int i = 2; i < limits; ++i)
        {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        }
        int temp = memo[limits - 1];
        // 점화식
        // 2번쨰 DP: 마지막꺼를 선택 안 하는 경우
        memset(memo, 0, sizeof(memo));
        memo[0] = nums[0];

        memo[1] = max(memo[0], nums[1]);

        for (int i = 2; i < limits - 1; ++i)
        {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        }
        return max(temp, memo[limits - 2]);
    }
};