
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

vector<int> parents;
vector<int> ranks;
int find(int x)
{
    if (parents[x] == x)
    {
        return x;
    }

    parents[x] = find(parents[x]);
    return parents[x];
}

bool unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY)
    {
        if (ranks[rootX] > ranks[rootY])
        {
            parents[rootY] = rootX;
        }
        else if (ranks[rootX] < ranks[rootY])
        {
            parents[rootX] = rootY;
        }
        else
        {
            parents[rootX] = rootY;
            ranks[rootY]++;
        }
        return true;
    }

    return false;
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    parents.resize(n);
    ranks.resize(n, 0);
    for (int i = 0; i < parents.size(); i++)
    {
        parents[i] = i;
    }
    
    int construction = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        int x = costs[i][0];
        int y = costs[i][1];
        bool result = unionSet(x, y);
        if (result)
        {
            answer += costs[i][2];
            ++construction;
            if (n == construction - 1)
            {
                break;
            }
        }
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
    int result = solution(n, costs);
}

