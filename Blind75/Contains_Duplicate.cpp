#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
오답노트
1. vector를 set에 넣으려면 정의할 때 아래와 같이 해야함.
set<int> tmp_nums(nums.begin(),nums.end());
-> set는 RBT 구조이기에, 삽입에 O(logN), 즉 전체 Time Complexity는 O(NlogN)이다.
2. lower bound 
-> 같거나 큰, 처음 등장, Index
3. 어떤 요소를 삭제하고 넣고 싶을 때 = rotate(start,middle,end = middle + 1)
-> [start,middle)를 middle부터 시작하는 위치로 이동
-> [middle, end)을 start부터 시작하는 위치로 이동
-> end을 포함하지 않는 다는 것이 포인트!!
-> 시간 복잡도 = O(N)
4. 왜 모범답안이 더 빠른가?
-> 빠른 탈출(사이즈가 1,2,3인 경우 빠른 결정)
-> 어떤 경우에도 전체 정렬을 해야하는 1차 답안와 달리 아래의 경우의 수를 단축시킴  
    a. 부분 정렬
    b. 정렬된 최댓값과의 비교 만으로 중복을 찾을 수있음
*/

// 1차 답안
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> tmp_nums(nums.begin(),nums.end());
        return tmp_nums.size() != nums.size();
    }
};

// 모범 답안
// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> &nums)
//     {
//         // 1. 사이즈가 3까지는 빠르게 결정
//         switch (nums.size())
//         {
//         case 0:
//             return false;
//         case 1:
//             return false;
//         case 2:
//             return nums.front() == nums.back();
//         }
//         // 2. 그보다 크다면 커서를 활용해서 중복검사를해야함.
//         auto const begin = nums.begin();
//         auto const end = nums.end();
//         for (auto cursor = begin + 1; cursor != end; cursor += 1)
//         {
//             if (SortCursor(begin, cursor))
//                 return true;
//         }
//         return false;
//     }

// private:
//     bool SortCursor(auto begin, auto cursor) const
//     {
//         //커서 딱 이전까지 소팅할거임
//         auto sortedEnd = cursor - 1;
//         if (*sortedEnd == *cursor) // 이때 커서와 마지막 아이템이 동일하다면 -> true
//             return true;
//         if (*sortedEnd < *cursor) // 이떄 커서보다 마지막 아이템이 작다면 -> 이미 소팅되었으니 false
//             return false;
//         // 커서 아이템보다 같거나 큰 최소 인덱스를 이분탐색 -> O(logN)
//         auto insertionPoint = (*begin > *cursor)
//                                   ? begin
//                                   : std::lower_bound(begin, cursor, *cursor);
//         // insertion point의 데이터가 커서와 같다면 -> true
//         if (*insertionPoint == *cursor)
//             return true;
//         std::rotate(insertionPoint, cursor, cursor + 1);
//         return false;
//     }
// };