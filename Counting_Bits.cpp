#include <vector>

using namespace std;
/*
오답노트
무조건: 최소 + 점화 + 최대 케이스 생각하자.
*/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1);
        // 이전꺼 * 2 == 다음꺼
        // 그 외의 것들은 이전 꺼에서 더하면 됨
        int local = 1;
        result[0] = 0;
        if(n == 0)
            return result;
        result[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            if (local * 2 == i)
            {
                local *= 2;
                result[i] = 1;
            }
            else
            {
                result[i] = 1 + result[i - local];
            }
        }
        return result;
    }
};