
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string preorder(vector<int> nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = to_string(nodes[idx]) + " ";
		ret += preorder(nodes, idx * 2 + 1);
		ret += preorder(nodes, idx * 2 + 2);
		return ret;
	}

	return "";
}

string inorder(vector<int> nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = inorder(nodes, idx * 2 + 1);
		ret += to_string(nodes[idx]) + " ";
		ret += inorder(nodes, idx * 2 + 2);
		return ret;
	}

	return "";
}

string postorder(vector<int> nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = postorder(nodes, idx * 2 + 1);
		ret += postorder(nodes, idx * 2 + 2);
		ret += to_string(nodes[idx]) + " ";
		return ret;
	}

	return "";
}

vector<string> solution(vector<int> nodes)
{
	vector<string> answer;

	string pre = preorder(nodes, 0);
	string inner = inorder(nodes, 0);
	string post = postorder(nodes, 0);

	pre.pop_back();
	inner.pop_back();
	post.pop_back();

	answer.push_back(pre);
	answer.push_back(inner);
	answer.push_back(post);
	return answer;
}

int main()
{
	vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };
	vector<string> result = solution(nodes);
}

