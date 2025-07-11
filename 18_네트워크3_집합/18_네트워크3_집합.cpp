
#include <vector>
#include <unordered_map>

using namespace std;

int parent[201];

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

void unionNodes(int node1, int node2)
{
    int root1 = findParent(node1);
    int root2 = findParent(node2);

    if (root1 != root2)
    {
        parent[root2] = root1;
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (computers[i][j])
            {
                unionNodes(i, j);
            }
        }
    }

    unordered_map<int, bool> networkFound;
    for (int i = 0; i < n; i++)
    {
        int root = findParent(i);
        if (!networkFound[root])
        {
            answer++;
            networkFound[root] = true;
        }
    }
    
    return answer;
}

int main()
{
    int n1 = 3;
    vector<vector<int>> computers1 = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };

    int n2 = 3;
    vector<vector<int>> computers2 = { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} };

    int result1 = solution(n1, computers1);
    int result2 = solution(n2, computers2);
}

