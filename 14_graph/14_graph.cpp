
#include <iostream>

#include <vector>

using namespace std;

struct nodeInfo
{
    int V; // 노드 번호
    int W; // 가중치
};

vector<vector<nodeInfo>> adjList;

void addEdge(int u, int v, int w)
{
    adjList[u].push_back({ v, w });
}

void printAdjList()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << "Node " << i << " : ";
        for (const auto& node : adjList[i])
        {
            cout << " -> (V : " << node.V << ", W:" << node.W << ")";
        }
        cout << endl;
    }
}

int main()
{
    int N = 5;
    adjList.resize(N);

    addEdge(1, 2, 3);
    addEdge(2, 1, 6);

    printAdjList();
}

