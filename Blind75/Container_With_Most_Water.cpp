#include <vector>
#include <set>
using namespace std;

/*
오답노트
1. unordered_map을 쓸 때, key값에 pair을 둔다면 아래와 같이 operator에 대한 struct을 지정해야합니다.

2. 단순히 Max,Min을 알아야된다면 kadane 알고리즘을 사용해라, 모든 memoization을 하는 DP말고
*/
struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

class Solution
{
public:
    int memo[100000][100000];
    int fnc(int l, int r, vector<int> &height)
    {
        if (l == r)
            return 0;
        if(memo[l][r] != 0)
            return memo[l][r];
        vector<int> temp({fnc(l + 1, r, height),
                          fnc(l, r - 1, height),
                          (r - l) * min(height[l], height[r])});
        cout << "L: " << l << " " << "R: " << r << " " << *max_element(temp.begin(), temp.end()) << endl;
        memo[l][r] = *max_element(temp.begin(), temp.end());
        return *max_element(temp.begin(), temp.end());
    }
    int maxArea(vector<int> &height)
    {
        // i,j가 양 끝에서 시작
        // f(i,j) 내부에서 제일 넓은 컨테이너의 value
        // f(i,j)는 f(i+1,j)랑, f(i,j-1)랑, (j-i) * (낮은거) 중 젤 큰거아님?
        int hlimit = height.size();
        memset(memo, 0, sizeof(memo));
        return fnc(0, hlimit - 1, height);
    }
};