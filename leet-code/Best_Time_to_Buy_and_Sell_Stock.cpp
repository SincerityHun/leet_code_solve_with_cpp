#include <vector>
#include <algorithm>

using namespace std;

// 오답노트
/*
greedy algorithm 사용 -> O(N)
모범답안이랑 발생했던 시간차이 이유
1. speedUp lambda function
2. 최솟값이 업데이트 되었다면 굳이 max_value을 새로 탐색할 필요가 없음 -> If 문 최적화
3. 최대한 함수 사용 금지 (min, max)
*/
int speedUp = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 싸게 사서 비싸게 팔자.
        // 앞에서부터 탐색
        // min(i) => i까지 탐색했을 때 최솟값
        // max_value(i) => i까지 탐색했을 때 최대 value
        //  i+1을 탐색할 때, max_value(i) 보다 prices[i+1] - min(i)가 크면 max_value(i+1)은 갱신아님?
        int min_value = prices[0];
        int max_value = 0;
        int limit = prices.size();
        for (int i = 1; i < limit; ++i)
        {
            if(min_value > prices[i])
                min_value = prices[i];
            else if (prices[i] - min_value > max_value)
                max_value = prices[i] - min_value;
        }
        return max_value;
    }
};
