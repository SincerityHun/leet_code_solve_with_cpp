#include <vector>
#include <string>

#define MAX_N 1000000000
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int cur_count = 1;
        // 위치 벡터 생성
        // 여기가 나오면 count가 증가하는 벡터를 정의해두는거임
        int conse[MAX_N*2 + 1]; // 0~2*10^9
        memset(conse, 0, sizeof(conse));
        // x가 들어옴
        // (x + 10^9)을 확인해봐, 여기 숫자 만큼 max값을 비교하는거임
        // conse[(x + 10^9)] 가 0이라면
            // 양쪽에 1넣기
        // conse[(x+10^9)]이 0이 아니라면 => 이미 이어지고 있는 시퀀스가 있었던거임
            // 여기에 1더한 값을 count랑 비교 후 업데이트
            // 오 왼 비교해서 0인쪽의 양끝으로 건너뛰어서 업데이트
    }
};