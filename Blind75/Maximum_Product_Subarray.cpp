#include <vector>

using namespace std;

/*
오답노트
1차시도: - + - 일때, cur이 +에서 업데이트 되는게 아닌 -도 포함해서 업데이트 해야하는 경우
[-2,3,-4] 포인트: -가 짝수 개 있는 걸 어떻게 하냐?
2차시도: negative을 부호를 정해서 음수는 따로 저장하면 안되나?
음수의 subary을 추적하기 어려움
최종: 왼 -> 오, 오 -> 왼 카데인 알고리즘 커스텀
왜?
*/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int cur_product = 1;
        int global_product = INT_MIN;
        // 1개씩 살피면서 cur보다 크면 초기화 해야함
        // 음수는 계속 가져가면서 cur과 비교해야된다는거임
        // global보다 얘가 크면 업데이트
        int limit = nums.size();
        for (int i = 0; i < limit; ++i)
        {
            cur_product = nums[i] * cur_product;
            if (global_product < cur_product)
                global_product = cur_product;
            if(cur_product == 0)
                cur_product = 1;
        }
        cur_product = 1;
        for (int i = limit - 1; i >= 0; --i)
        {
            cur_product = nums[i] * cur_product;
            if (global_product < cur_product)
                global_product = cur_product;
            if(cur_product == 0)
                cur_product = 1;
        }
        return global_product;
    }
};