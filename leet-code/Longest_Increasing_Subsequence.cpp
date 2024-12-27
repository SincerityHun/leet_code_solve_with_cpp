#include <vector>

using namespace std;

/*

*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // Sorting Ary을 만들기
        // 9
        // 2
        // 2 5
        // 2 3
        // 2 3 7
        // 2 3 7 101
        vector<int> sorted_ary;
        int cur_largest = 1;
        sorted_ary.emplace_back(nums[0]);
        int limit = nums.size();
        for (int i = 1; i < limit;++i)
        {
            if(nums[i] > sorted_ary[cur_largest - 1]){
                sorted_ary.emplace_back(nums[i]);
                ++cur_largest;
                continue;
            }
            auto it = lower_bound(sorted_ary.begin(), sorted_ary.end(), nums[i]);
            sorted_ary.erase(it);
            sorted_ary.insert(it, nums[i]);
        }
        return cur_largest;
    }
};