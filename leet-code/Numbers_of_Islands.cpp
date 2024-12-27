#include <vector>
#include <queue>
using namespace std;

// queue<pair<int, int>> bfs;

// // 상 우 하 좌
// int dir_r[4] = {-1, 0, 1, 0};
// int dir_c[4] = {0, 1, 0, -1};
// int N;
// int M;
// bool is_range(int x, int y)
// {
//     return (0 <= x) && (x < N) && (0 <= y) && (y < M);
// }
// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int island_num = 0;
//         N = grid.size();
//         M = grid[0].size();
//         for (int i = 0; i < N; ++i)
//         {
//             for (int j = 0; j < M; ++j)
//             {
//                 // 0 이면 pass
//                 if (grid[i][j] == '0')
//                     continue;
//                 // 1 이면 BFS
//                 bfs = queue<pair<int, int>>();
//                 bfs.push({i, j});
//                 grid[i][j] = '0';
                
//                 while (!bfs.empty())
//                 {
//                     auto [cur_x, cur_y] = bfs.front();
//                     bfs.pop();
//                     for (int dir = 0; dir < 4; ++dir)
//                     {
//                         int next_x = cur_x + dir_r[dir];
//                         int next_y = cur_y + dir_c[dir];
//                         if (!is_range(next_x, next_y))
//                             continue;
//                         if(grid[next_x][next_y] == '0')
//                             continue;
//                         grid[next_x][next_y] = '0';
//                         bfs.push({next_x, next_y});
//                     }
//                 }
//                 // 다 돌았으면 island_num 추가
//                 ++island_num;
//             }
//         }
//         return island_num;
//     }
// };

#include <vector>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};