#include <cstring>

using namespace std;

class Solution
{
public:
    int memo[46];
    int rec_x(int x)
    {
        if(x == 1)
            return 1;
        if(x == 2)
            return 2;
        if(memo[x]!=0)
            return memo[x];
        memo[x] = rec_x(x - 1) + rec_x(x - 2);
        return memo[x];
    }
    int climbStairs(int n)
    {
        // f(x): x까지 갈 수 있는 모든 경우의 수
        // f(x+1): f(x)랑 똑같지
        // f(x+2): f(x) * 2(1+1, 2) + f(x+1)
        memset(memo, 0, sizeof(memo));
        memo[1] = 1;
        memo[2] = 2;

        return rec_x(n);
    }
};