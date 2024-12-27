#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 정렬
        // coin의 종류에 있어 x개 있을 때 amount만큼 되나요?
        // DP
        // f(N) N amount을 달성하기 위해 필요한 최소한의 코인
        vector<int> memo(amount + 1,-1); // memo[x] = x가격만큼 도달하려면 필요한 코인의 최소 개수
        memo[0] = 0;
        for (int t_amount = 1; t_amount < amount + 1; ++t_amount)
        {
            for (int t_coin : coins)
            {
                if(t_amount - t_coin < 0)
                    continue;
                if(memo[t_amount - t_coin] == -1)
                    continue;
                if(memo[t_amount] != -1)
                    memo[t_amount] = min(memo[t_amount], memo[t_amount - t_coin] + 1);
                else
                    memo[t_amount] = memo[t_amount - t_coin] + 1;
            }
        }
        return memo[amount];
    }
};