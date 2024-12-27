#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
/*
오답노트
- 언제 크루스칼(Union Find)
    -> Minimum Spanning tre
        가중치가 작은 간선들부터 순서대로 확인하면서 간선이 연결하는 두 정점이 연결되지 않았다면 연결함
        이때 연결이 되었는 지 안되었는 지 찾기 위해 Union-Find을 사용한다.
        각자 부모를 찾고, 같은 그룹이면 넘어가고 다르다면 하나로 합치는 방식
- 그럼 사이클을 찾는건 어떻게 찾으면 될까?
    -> 순서가 중요해? -> Topological Sort\
        # in_degree가 0인 정점을 큐에 삽입하고 방문 표시
        
*/
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        for (auto x : prerequisites)
        {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for (auto x : adj[t])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return ans.size() == numCourses;
    }
};