
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int idx, x, y;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int idx, int x, int y) : idx(idx), x(x), y(y) {}
};

class BinaryTree
{
private:
    Node* root = nullptr;

    static bool compareNodes(Node* a, Node* b)
    {
        if (a->y != b->y) // 1. y값 큰 순
        {
            return a->y > b->y;
        }
        return a->x < b->x; // 2. x값 작은 순
    }

    Node* addNode(Node* current, Node* newNode)
    {
        if (current == nullptr) // 해당 노드가 비었으면 추가
        {
            return newNode;
        }
        if (newNode->x < current->x)
        {
            current->left = addNode(current->left, newNode);
        }
        else
        {
            current->right = addNode(current->right, newNode);
        }
        return current;
    }

    // traversal 벡터에 노드의 인덱스만 저장해서 반환
    void preOrder(Node* node, vector<int>& traversal)
    {
        if (node == nullptr)
        {
            return;
        }
        traversal.push_back(node->idx);
        preOrder(node->left, traversal);
        preOrder(node->right, traversal);
    }

    void postOrder(Node* node, vector<int>& traversal)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left, traversal);
        postOrder(node->right, traversal);
        traversal.push_back(node->idx);
    }

public:
    BinaryTree() : root(nullptr) {}

    void buildTree(const vector<vector<int>>& nodeInfo)
    {
        vector<Node*> nodes;
        for (int i = 0; i < nodeInfo.size(); i++)
        {
            nodes.push_back(new Node(i + 1, nodeInfo[i][0], nodeInfo[i][1]));
        }

        sort(nodes.begin(), nodes.end(), compareNodes);

        for (Node* node : nodes)
        {
            root = addNode(root, node);
        }
    }

    vector<int> getPreOrderTraversal()
    {
        vector<int> traversal;
        preOrder(root, traversal);

        return traversal;
    }

    vector<int> getPostOrderTraversal()
    {
        vector<int> traversal;
        postOrder(root, traversal);
        return traversal;
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    BinaryTree tree;

    tree.buildTree(nodeinfo);
    vector<int> preOrder = tree.getPreOrderTraversal();
    vector<int> postOrder = tree.getPostOrderTraversal();

    return { preOrder, postOrder };
}

int main()
{
    vector<vector<int>> nodeinfo = { {5,3} ,{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    vector<vector<int>> result = solution(nodeinfo);
}
