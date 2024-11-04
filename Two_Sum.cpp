#include <vector>
#include <unordered_map>
#include <algorithm>
//오답노트
// unordered_map에서 key는 hash로 저장됨
// find 메서드를 통해 key 유무를 확인할 수 있으며 이를 활용한 아이디어 부족
// 시간복잡도 = O(N)

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> lookUp; // look up[nums값] = nums index

        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i]; // 현재 nums의 차잇값
            // 진즉 탐색한 key 중에서 있다면?
            if (lookUp.find(diff) != lookUp.end())
            {
                // 그 인덱스랑 현재값 반환
                return {lookUp[diff], i};
            }

            lookUp[nums[i]] = i;
        }

        return {};
    }
};