#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
오답노트
1차시도: 시간 복잡도는 최악을 상정하고 계산하자.

모범답안: 2-pointer을 사용해 O(N^2)노리자
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 최대 3000 C 3 => 걍 세는건 시간초과
        // 대충 O(N^2)으로 끊으란 소리
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        int limits = nums.size();
        int j, k,temp;
        for (int i = 0; i < limits - 2; ++i)
        {
            j = i + 1;
            k = limits - 1;
            while(j < k){
                temp = nums[i] + nums[j] + nums[k];
                if(temp == 0){
                    result.insert({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }
                else if(temp < 0){
                    ++j;
                }
                else{
                    --k;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};