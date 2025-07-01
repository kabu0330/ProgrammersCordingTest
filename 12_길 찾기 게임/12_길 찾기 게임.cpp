
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int index = -1;

class Node
{
public:
    vector<int> coord = { 0, 0 };
    int idx = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int x, int y)
    {
        coord[0] = x;
        coord[1] = y;
        idx = ++index;
    }
};

class BST
{
private:
    Node* root = nullptr;

public:
    void insert(vector<int> value)
    {
        Node* node = new Node(value[0], value[1]);
        if (nullptr == root)
        {
            root = node;
        }
        else
        {
            int rootX = root->coord[0];
            int rootY = root->coord[1];
            int valueX = node->coord[0];
            int valueY = node->coord[1];
            if (rootY < valueY)
            {
                if (rootX < valueX)
                {
                    while
                }
            }
        }

    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = { {5,3} ,{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    vector<vector<int>> result = solution(nodeinfo);
}
