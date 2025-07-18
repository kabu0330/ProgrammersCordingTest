#pragma once

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

long long polynomial_hash(const string& str)
{
	const int p = 31;
	const long long m = 1000007;
	long long hash_value = 0;

	for (char ch : str)
	{
		hash_value = (hash_value * p + ch) % m;
	}
	return hash_value;
}

vector<bool> solution2(vector<string> string_list, vector<string> query_list)
{
	unordered_set<long long> hash_set;
	for (const string& str : string_list)
	{
		long long hash = polynomial_hash(str);
		hash_set.insert(hash);
	}

	vector<bool> result;
	for (const string& query : query_list)
	{
		long long query_hash = polynomial_hash(query);
		bool found = (hash_set.find(query_hash) != hash_set.end());
		result.push_back(found);
	}

	return result;
}