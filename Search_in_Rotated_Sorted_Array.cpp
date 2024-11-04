#include <vector>
#include <gi
using namespace std;

/*
오답노트: 뭐가 핵심인지 찾아야 한다.
사고 순서
1. 정렬된 상태에서 O(log N)의 시간복잡도를 가진 탐색방법으로 이진탐색을 사용할 수 있겠다
2. 정렬이 중간에 끊어져있다.
3. 정렬이 된 곳에서만 탐색을 하면 되겠다.

*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 이분탐색아닌가?
        //  경우의 수
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int result = -1;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if(right - left == 1){
                break;
            }
            if(nums[left] < nums[mid]) { //왼쪽이 정렬 상태
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            else if(nums[right] > nums[mid]){ // 오른쪽이 정렬 상태
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
        }
        if(nums[left] == target)
            result = left;
        else if(nums[right] == target)
            result = right;
        return result;
    }
};