#include <vector>
#include <iostream>
using namespace std;
/* 
오답노트
- 이분탐색 접근 굿
1. 시뮬 -> 생각
*/
// 1차 시도
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int left = 0;
        int right = nums.size()-1;
        int prev_left = 0;
        while (left < right)
        {
            cout << left << " " << right << endl;
            if (right - left == 1)
                break;

            if (nums[left] > nums[right])
            {
                prev_left = left;
                left = left + (right - left) / 2;
            }
            else
            {
                right = left;
                left = prev_left;
            }
        }
        return nums[right] > nums[left] ? nums[left] : nums[right];
    }
};

/* 모범 답안 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        int min = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= nums[low])
            {
                if (min > nums[low])
                {
                    min = nums[low];
                }
                low = mid + 1;
            }
            else
            {
                if (min > nums[mid])
                {
                    min = nums[mid];
                }
                high = mid - 1;
            }
        }
        return min;
    }
};