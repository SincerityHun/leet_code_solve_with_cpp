#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;
/*
오답노트
- Process는 실행 중에 필요한 동적 메모리를 Heap에 저장함
    Heap은 Process마다 독립적인 공간, Process의 모든 Thread가 공유함
    Stack은 함수 호출 시  생성되는 지역 변수 및 함수의 리턴 주소, 매개변수가 저장됨
    이러한 Stack은 함수 호출이 끝나면 자동으로 메모리를 해제하며, 모든 스레드는 각자의 스택을 가짐.

- 만약에 vector<Node> db(100,Node())로 생성을 한다면, 이는 Stack에 저장된다.
    그래서 이 함수가 끝나면 사라지고, 여기에 대한 포인터를 백날 반환해봤자 아무것도 안남는다.

- 그래서 vector<Node*> db(100,nullptr)로 정의하고, 매번 방문할 때마다
    Node* node = new Node();
    로 하게 된다면 메모리를 동적으로 할당해 딥카피를 수행한 결과를 반환할 수 있다.
*/
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        vector<Node *> db(101, nullptr); // 최대 100개, nullptr로 초기화
        int cur_id = node->val;
        Node *result = new Node(cur_id);
        db[cur_id] = result;

        // BFS로 그래프를 복사
        set<int> visited;
        queue<Node *> bfs;
        bfs.push(node);

        while (!bfs.empty())
        {
            Node *cur_node_ptr = bfs.front();
            bfs.pop();

            if (visited.count(cur_node_ptr->val) != 0)
                continue;

            visited.insert(cur_node_ptr->val);
            Node *cur_clone_node = db[cur_node_ptr->val];

            // 각 이웃 노드를 처리
            for (auto &neighbor : cur_node_ptr->neighbors)
            {
                if (db[neighbor->val] == nullptr)
                {
                    db[neighbor->val] = new Node(neighbor->val);
                    
                }
                
                bfs.push(neighbor);
                cur_clone_node->neighbors.push_back(db[neighbor->val]);
            }
        }

        return result;
    }
};
