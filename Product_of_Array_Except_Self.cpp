#include <vector>
using namespace std;

/*
오답노트
- 어떤 값들이 곱해져서 결과를 뽑는 지 생각하기
- O(N)이라면, for문 하나를 여러번이라고 생각하기
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        //숫자 : index
        //left -> right, right -> left loop 돌기?
        // 각 루프를 돌때, 현재 index을 제외한 곱을 곱해두는거
        // 1, 2, 3, 4
        // []
        vector<int> output;
        int limit = nums.size();
        for (int i = 0; i < limit; ++i){
            output.emplace_back(1);
        }
        //left loop
        int left = 1;
        for (int i = 0; i < limit-1; ++i)
        {
            //현재 넘값을 레프트에 곱하기
            left *= nums[i];
            // 레프트값을 인덱스 +1인 아웃풋에 곱하기
            output[i + 1] *= left;
        }
        //right loop
        int right = 1;
        for (int i = limit - 1; i > 0; --i)
        {
            right *= nums[i];
            output[i - 1] *= right;
        }
        return output;
    }
};