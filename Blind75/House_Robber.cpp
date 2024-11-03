#include <vector>
#include <cstring>
using namespace std;

// 1차 시도 -> BackTracking : Timeout O(2^n) ->중간에 가지치기를 안하니까 그냥 DFS인거임
// class Solution
// {
// public:
//     int max_v;
//     void bck(int index, int c_value, vector<int>& nums)
//     {
//         if(index >= nums.size())
//         {
//             max_v = max(max_v, c_value);
//             return;
//         }
//         //얘를 먹은 경우
//         bck(index + 2, c_value + nums[index], nums);
//         bck(index + 1, c_value, nums);
//     }
//     int rob(vector<int> &nums)
//     {
//         // 연속된걸 털면 간다?
//         // f(x) -> x까지 털었을 떄 최댓값
//         // f(x+1)
//         max_v = 0;
//         bck(0, 0, nums);
//         return max_v;
//     }
// };

// 2차 시도 -> DP: O(N)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // f(x,0) -> x까지 털때 x를 턴 경우
        // f(x,1) -> x까지 털때 x를 안 턴 경우
        int limits = nums.size();
        int memo[limits];
        memset(memo, 0, sizeof(memo));
        memo[0] = nums[0];
        if (limits == 1)
            return memo[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < limits; ++i)
        {
            // 전에 있던걸 안썼다면 memo[i-1]이랑 memo[i-2]가 같을거임
            // 그래서 지금 걸린걸 쓴다고 가정하면, memo[i-2] + nums[i]
            // 전에 있던걸 썼다면 memo[i-1]로 해야됨
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo[limits - 1];
    }
};