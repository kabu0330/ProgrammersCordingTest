#include <iostream>
#include <chrono>   // C++ Standard Library Chrono

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

// new 연산 시간 측정
void MeasureNew(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    // 힙(heap) 메모리에서 int 1개씩 할당
    for (int I = 0; I < _Count; I++)
    {
        int* Ptr = new int;
        delete Ptr;
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "new x " << _Count
        << " : " << Duration << " ms\n";
    cout << endl;
}

// vector<bool> 푸시백(push_back) 시간 측정
void MeasureVectorBool(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    vector<bool> BoolVec;
    BoolVec.reserve(_Count);

    for (int I = 0; I < _Count; I++)
    {
        BoolVec.push_back((I % 2) == 0);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "vector<bool> push_back x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (int I = 0; I < _Count; I++)
    {
        BoolVec[I] = (I % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "vector<bool> for x " << _Count
        << " : " << Duration3 << " ms\n";

    //// 삭제
    //auto Start2 = chrono::high_resolution_clock::now();
    //while (!BoolVec.empty())
    //{
    //    auto Begin = BoolVec.begin();
    //    BoolVec.erase(Begin);
    //}

    //auto End2 = chrono::high_resolution_clock::now();

    //auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
    //    End2 - Start2).count();

    //cout << "vector<bool> erase x " << _Count
    //    << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureVectorInt(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    vector<int> Vec;
    Vec.reserve(_Count);

    for (int I = 0; I < _Count; I++)
    {
        Vec.push_back((I % 2) == 0);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "vector<int> push_back x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (int I = 0; I < _Count; I++)
    {
        Vec[I] = (I % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "vector<int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Vec.empty())
    {
        auto Begin = Vec.begin();
        Vec.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "vector<int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureList(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    list<int> List;

    for (int I = 0; I < _Count; I++)
    {
        List.push_back((I % 2) == 0);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "List<int> push_back x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (int Value : List)
    {
        Value = (Value % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "list<int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!List.empty())
    {
        auto Begin = List.begin();
        List.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "list<int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureMap(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    map<int, int> Map;

    for (int I = 0; I < _Count; I++)
    {
        Map.insert({ I, I * 2 });
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Map<int, int> insert x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (auto Value : Map)
    {
        Value.second = (Value.second % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "Map<int, int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Map.empty())
    {
        auto Begin = Map.begin();
        Map.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Map<int, int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureSet(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    set<int> Set;

    for (int I = 0; I < _Count; I++)
    {
        Set.insert(I);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Set<int> insert x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (auto Value : Set)
    {
        Value = (Value % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "Set<int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Set.empty())
    {
        auto Begin = Set.begin();
        Set.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Set<int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureUnorderedSet(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    unordered_set<int> Set;

    for (int I = 0; I < _Count; I++)
    {
        Set.insert(I);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Unordered Set<int> insert x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (auto Value : Set)
    {
        Value = (Value % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "Unordered Set<int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Set.empty())
    {
        auto Begin = Set.begin();
        Set.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Unordered Set<int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureUnorderedMap(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    unordered_map<int, int> Map;

    for (int I = 0; I < _Count; I++)
    {
        Map.insert({ I, I * 2 });
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Unordered Map<int, int> insert x " << _Count
        << " : " << Duration << " ms\n";

    // 탐색
    auto Start3 = chrono::high_resolution_clock::now();

    for (auto Value : Map)
    {
        Value.second = (Value.second % 2) == 1;
    }
    auto End3 = chrono::high_resolution_clock::now();

    auto Duration3 = chrono::duration_cast<chrono::milliseconds>(
        End3 - Start3).count();

    cout << "Unordered Map<int, int> for x " << _Count
        << " : " << Duration3 << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Map.empty())
    {
        auto Begin = Map.begin();
        Map.erase(Begin);
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Unordered Map<int, int> erase x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureQueue(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    queue<int> Queue;

    for (int I = 0; I < _Count; I++)
    {
        Queue.push((I % 2) == 0);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Queue<int> push x " << _Count
        << " : " << Duration << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Queue.empty())
    {
        Queue.pop();
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Queue<int> pop x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

void MeasureStack(int _Count)
{
    auto Start = chrono::high_resolution_clock::now();
    stack<int> Stack;

    for (int I = 0; I < _Count; I++)
    {
        Stack.push((I % 2) == 0);
    }
    auto End = chrono::high_resolution_clock::now();

    auto Duration = chrono::duration_cast<chrono::milliseconds>(
        End - Start).count();

    cout << "Stack<int> x " << _Count
        << " : " << Duration << " ms\n";

    // 삭제
    auto Start2 = chrono::high_resolution_clock::now();
    while (!Stack.empty())
    {
        Stack.pop();
    }

    auto End2 = chrono::high_resolution_clock::now();

    auto Duration2 = chrono::duration_cast<chrono::milliseconds>(
        End2 - Start2).count();

    cout << "Stack<int> pop x " << _Count
        << " : " << Duration2 << " ms\n";
    cout << endl;
}

int main()
{
    const int Count = 1000000; // 1백만 번 반복

    MeasureNew(Count);
    MeasureList(Count);
    MeasureVectorInt(Count);
    MeasureVectorBool(Count);


    MeasureMap(Count);
    MeasureSet(Count);
    MeasureUnorderedMap(Count);
    MeasureUnorderedSet(Count);

    MeasureQueue(Count);
    MeasureStack(Count);



    return 0;
}