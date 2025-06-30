
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compareGenres(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

bool compareSongs(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> genres_dict;
    unordered_map<string, int> play_dict;

    for (int i = 0; i < genres.size(); i++)
    {
        genres_dict[genres[i]].push_back({ i, plays[i] });
        play_dict[genres[i]] += plays[i];
    }

    vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());
    sort(sorted_genres.begin(), sorted_genres.end(), compareGenres);

    for (auto& genre : sorted_genres)
    {
        auto& songs = genres_dict[genre.first];
        sort(songs.begin(), songs.end(), compareSongs);

        for (int i = 0; i < min(2, (int)songs.size()); i++)
        {
            answer.push_back(songs[i].first);
        }
    }

    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> result = solution(genres, plays);
    
    for (int var : result)
    {
        cout << var << ", " << endl;
    }
}

