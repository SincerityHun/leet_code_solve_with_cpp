#include <cstring>
#include <vector>

using namespace std;
/*
오답노트
-> 거꾸로 사용도 가능하네?
*/
// 1차 시도 -> Greedy? 통과는 되었는데 O(N^2)이고 하위 문제 결과를 사용하는게 아니니 시간이 오래걸림
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // dp [] 여기까지 오는게 가능하다면 true, 못하다면 false
        int limit = nums.size();
        if (limit == 1)
            return true;
        int dp[limit]; // 0이면 불가, 1이면 가능
        memset(dp, 0, sizeof(dp));

        // 초
        dp[0] = 1;

        for (int i = 0; i < limit; ++i)
        {
            if(!dp[i])
                continue;
            for (int j = 1; j <= nums[i];++j){
                if(i+j >=limit)
                    break;
                dp[i + j] = 1;
            }
        }
        return dp[limit - 1];
    }
};

//2차 시도 -> DP
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }

        return goal == 0;
    }
};