#include <vector>

using namespace std;
/*
오답노트
- 한번 계산한 하위문제를 그대로 상위문제에 이용하는 느낌
- 계산 과정을 머리로 훑어야 순회를 역으로 할지 순으로 할지 정할 수 있다.
*/
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int resultant_sums = 0;
        // 결과 계산
        for (auto x : nums)
            resultant_sums += x;

        // 조기 종료
        if (resultant_sums % 2)
            return false;

        // 초기화
        resultant_sums /= 2;
        vector<int> dp(resultant_sums + 1, 0); // dp[x] x에 도달할 수 있으면 1, 없으면 0
        dp[0] = 1;

        // 순회
        for (int &x : nums)
        {
            
            for (int i = resultant_sums; i >= x; --i){
                dp[i] = dp[i] || dp[i - x];
            }
        }
        return dp[resultant_sums];
    }
};