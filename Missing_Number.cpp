#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // O(1) - Space Complexity
        // O(n) - runtime Complexity
        // n => 사이즈 구하면 0~n까지 합이 나오면 하나씩 뺸 결과가 그거겠네
        int n = nums.size();
        int sum_n = (n * (n + 1)) / 2;
        for(int x: nums){
            sum_n -= x;
        }
        return sum_n;
    }
};