#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    for (auto&  wire : wires)
    {
        int a = wire[0];
        int b = wire[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_diff = INT_MAX;
    for (auto&  wire : wires)
    {
        int a = wire[0];
        int b = wire[1];

        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
    }
    
    return 0;       
}

int main(int argc, char* argv[])
{
    int n = 9;
    vector<vector<int>> wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
    int result = solution(n, wires);
    return 0;
}
