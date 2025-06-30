
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    vector<string> ids;
    vector<string> commands;
    unordered_map<string, string> idAndName;
    
    for (int i = 0; i < record.size(); i++)
    {
        string code = record[i];
        string command = code.substr(0, code.find(' '));
        commands.push_back(command);
        code.erase(0, code.find(' ') + 1);

        string id = code.substr(0, code.find(' '));
        ids.push_back(id);
        if (id.length() != code.length())
        {
            code.erase(0, code.find(' ') + 1);
            string name = code;
            idAndName[id] = name;
        }
    }

    for (int i = 0; i < commands.size(); i++)
    {
        string str = idAndName[ids[i]] + "님이 ";
        if ("Enter" == commands[i])
        {
            str += "들어왔습니다.";
        }
        else if ("Leave" == commands[i])
        {
            str += "나갔습니다.";
        }
        else if ("Change" == commands[i])
        {
            continue;
        }

        answer.push_back(str);
    }

    return answer;
}

int main()
{
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    
    vector<string> result = solution(record);
    
    for (const string& str : result)
    {
        cout << str << endl;
    }
}

