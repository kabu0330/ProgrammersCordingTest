

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n;
int matrix[26][26] = {};
bool visited[26][26] = {};

int dfs(int y, int x)
{
    int token = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] || matrix[ny][nx] == 0) continue;

        token += dfs(ny, nx);
    }
    return token;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            matrix[i][j] = str[j] - '0';
        }
    }

    // 총 단지 수 계산
    vector<int> complex;
    int cnt = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (!visited[y][x] && matrix[y][x] == 1)
            {
                ++cnt;
                complex.push_back(dfs(y, x));
            }
        }
    }

    // 오름차순 정렬
    sort(complex.begin(), complex.end());

    // 출력
    cout << cnt << '\n';
    
    for (int i = 0; i < complex.size(); i++)
    {
        cout << complex[i] << '\n';
    }
}

