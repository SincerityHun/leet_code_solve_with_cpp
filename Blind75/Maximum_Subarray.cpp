#include <vector>

using namespace std;

/*
오답노트
1차시도: [1,2,-1,-2,2,1,-2,1,4,-5,4] Edge Case -> [2,1,-2,1,4]로 나와야함
        이때, right 그 자체 value가 크지만 누적합이 작은 경우가 있음
        그래서 그냥 전체 재귀
2차시도: timeout O(2^N)
모범답안: Kadane's Algorithm O(N)
        현재 시점까지의 최대값을 계속 저장해두는 거임
*/
//1차시도
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int result = 0;
//         for(int x: nums)
//             result += x;
//         result = rec_subary(nums, 0, nums.size() - 1, result);
//         return result;
//     }

// private:
//     int rec_subary(vector<int> &nums, int left, int right,int cur_value){
//         //cur_value: left~right까지 합
//         if(left == right)
//             return cur_value;
//         // 검사를 할거임
//         // left value < right value -> left++ rec, cur_value 변경,
//         // left value > right value -> right-- rec, cur_value 변경,
//         // 같 다면 둘다 해봐야함
//         cout << left << " " << right << ": " << cur_value << endl;
//         int upt_value = cur_value;
//         if (nums[left] == nums[right])
//         {
//             upt_value = max(upt_value,rec_subary(nums, left+1, right, cur_value - nums[left]));
//             upt_value = max(upt_value, rec_subary(nums, left, right-1, cur_value - nums[right]));
//         }
//         else if (nums[left]> nums[right])
//         {
//             upt_value = max(upt_value, rec_subary(nums, left, right-1, cur_value - nums[right]));
            
//         }
//         else{
//             upt_value = max(upt_value, rec_subary(nums, left+1, right, cur_value - nums[left]));
//         }
        
//         // upt 값이 cur_value보다 크다면 그 값 반환
//         return upt_value;
//     }
// };

//모범 답안
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_current = nums[0];
        int max_global = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            max_current = max(nums[i], max_current + nums[i]);
            if (max_current > max_global)
            {
                max_global = max_current;
            }
        }

        return max_global;
    }
};