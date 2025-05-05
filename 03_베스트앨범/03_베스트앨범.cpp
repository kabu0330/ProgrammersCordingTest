#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool CompareSongs(const std::pair<int, int>& A, const std::pair<int, int>& B)
{
    if (A.first == B.first) // 플레이 수가 같으면 인덱스 비교
    {
        return A.second < B.second; // 인덱스는 낮은게 우선
    }
    return A.first > B.first; // 플레이 수는 높은게 우선
}

bool CompareGenres(const std::pair<std::string, int>& A, const std::pair<std::string, int>& B)
{
    return A.second > B.second;
}

// map<장르 sort<<플레이, 인덱스>.begin(), end(), std::greate<>>
vector<int> solution(vector<string> genres, vector<int> plays) 
{
    //                     장르  ,                 플레이 수, 인덱스
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> GenreToSongs;
    std::unordered_map<std::string, int> GenrePlayCount;

    // 1. 복사
    for (size_t i = 0; i < genres.size(); i++)
    {
        GenreToSongs[genres[i]].push_back({ plays[i], i });
        GenrePlayCount[genres[i]] += plays[i];
    }

    std::vector<std::pair<std::string, int>> GenreList(GenrePlayCount.begin(), GenrePlayCount.end());
    std::sort(GenreList.begin(), GenreList.end(), CompareGenres);
    
    std::vector<int> answer;
    for (const std::pair<std::string, int>& Genre : GenreList)
    {
        std::vector<std::pair<int, int>> Songs = GenreToSongs[Genre.first];
        std::sort(Songs.begin(), Songs.end(), CompareSongs);
        for (size_t i = 0; i < Songs.size() && i < 2; i++)
        {
            answer.push_back(Songs[i].second);
        }
    }
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
;
    for (size_t i = 0; i < solution(genres, plays).size(); i++)
    {
        std::cout << solution(genres, plays)[i] << ", ";
    }

}

