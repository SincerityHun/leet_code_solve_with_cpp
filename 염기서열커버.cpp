#include <iostream>
#include <vector>

#define MAX_N 15
#define MAX_M 20

using namespace std;

int N;
int M;
char matrix[MAX_N][MAX_M];
struct Node
{
    char value;
    int level;
    vector<Node *> next;
};
void create_node(Node *item, char value, int level)
{
    item->value = value;
    item->level = level;
    return;
}
int get_level(Node *target, int i, int j) // matrix[i][j]가 같으면 ㄱㄱ
{
    // target의 next 목록 중에서 같거나 .인게 있으면
    if (target->value != '.' && matrix[i][j] != '.' && target->value != matrix[i][j])
    {
        return target->level;
    }
    if (target->next.empty())
    {
        return target->level;
    }
    if (j == M - 1)
    {
        return target->level;
    }
    // 현재 타겟이랑 적합하고, 다음을 바라바도 괜찮다는 뜻
    int max_distance = 0;
    for (Node *next_item : target->next)
    {
        max_distance = max(max_distance, get_level(next_item, i, j + 1));
    }
    return max_distance;
}

int count_level(Node *target)
{
    if (target->next.empty())
    {
        if (target->level == M - 1)
        {
            return 1;
        }
        return 0;
    }
    int result = 0;
    for (Node *next_item : target->next)
    {
        result += count_level(next_item);
    }
    return result;
}

int main(int argc, char **argv)
{
    int limit;
    cin >> N >> M;
    char input_char;
    Node *root = new Node;
    create_node(root, '.', 0);
    /*
    tree?
    넣으려는데 .만 있다? -> 대체
    넣으려는게 . 이다? -> 그 level DFS 후 멀리 가는거에 넣어준다.
    */
    Node *next_item;
    // 전부 입력 받고
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // tree에 넣기
    /*
    넣으려는게 . 인 경우 -> 현재 level DFS 후 어디까지 멀리가는거에 넣어주자
    넣으려는게 그게 아닌 경우 -> .만 있으면 그냥 대체, .이 아닌게 있으면 그냥 추가
    */
    for (int i = 0; i < N; ++i)
    {
        Node *target = root;
        for (int j = 0; j < M; ++j)
        {
            if (matrix[i][j] == '.')
            {
                int max_distance = 0;
                Node *max_node = nullptr;
                for (Node *next_node : target->next)
                {
                    int temp_dist = get_level(next_node, i, j);
                    if (max_distance < temp_dist)
                    {
                        max_distance = temp_dist;
                        max_node = next_node;
                    }
                }
                if (max_node == nullptr)
                {
                    max_node = new Node;
                    create_node(max_node, '.', j);
                    target->next.emplace_back(max_node);
                }
                target = max_node;
                continue;
            }
            bool flag = false;
            for (Node *next_node : target->next)
            {
                if (next_node->value == '.')
                {
                    // 그냥 대체
                    next_node->value = matrix[i][j];
                    target = next_node;
                    flag = true;
                    break;
                }
                if (next_node->value == matrix[i][j])
                {
                    // 이걸로 ㄱ
                    target = next_node;
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            // 다 해당안되면 새로 만들어야지
            Node *new_node = new Node;
            create_node(new_node, matrix[i][j], j);
            target->next.emplace_back(new_node);
            target = new_node;
        }
    }

    cout << count_level(root) << endl;
    return 0;
}