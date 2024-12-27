#include <string>
#include <vector>
#include<iostream>
using namespace std;
/*
1. 변수명 확인 => 원래 변수랑 prefix을 다르게 둘 것
2. 테케는 언제나 => 최소값, 일반값, 최댓값 으로 3개 고려 하고 로직 짤것
*/
bool is_range(int pos[], int op_start[], int op_end[])
{
    if (op_start[0] > pos[0] || pos[0] > op_end[0])
        return false;
    if (op_start[0] < pos[0] && pos[0] < op_end[0])
    {
        return true;
    }
    if (op_start[0] == pos[0] && op_start[1] > pos[1])
        return false;
    if (op_end[0] == pos[0] && op_end[1] < pos[1])
        return false;
    return true;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    // "prev" => 10초전, 10초 미만이라면 영상의 처음 위치(0분 0초)
    // "next" => 10초후, 남은게 10초 미만이라면 영상의 마지막 위치(동영상길이)
    // 오프닝건너뛰기 => op_start <= 현재 위치 <=op_end라면 자동으로 오프닝 끝나는 위치
    int op_start_int[2] = {stoi(op_start.substr(0, 2)), stoi(op_start.substr(3, 2))};
    int op_end_int[2] = {stoi(op_end.substr(0, 2)), stoi(op_end.substr(3, 2))};
    int pos_int[2] = {stoi(pos.substr(0, 2)), stoi(pos.substr(3, 2))};
    int video_len_int[2] = {stoi(video_len.substr(0, 2)), stoi(video_len.substr(3, 2))};
    for (string command : commands)
    {
        // 시작 전에 범위 검사 후 수정
        if (is_range(pos_int, op_start_int, op_end_int))
        {
            pos_int[0] = op_end_int[0];
            pos_int[1] = op_end_int[1];
        }
        // command에 맞춰 ㄱ
        if (command.compare("prev") == 0)
        {
            pos_int[1] -= 10;
            if (pos_int[1] < 0)
            {
                pos_int[1] += 60;
                pos_int[0] -= 1;
            }
            if (pos_int[0] < 0)
            {
                pos_int[0] = 0;
                pos_int[1] = 0;
            }
        }
        else
        {
            // TODO
            pos_int[1] += 10;
            if (pos_int[1] > 59)
            {
                pos_int[1] -= 60;
                pos_int[0] += 1;
            }
            if ((pos_int[0] > video_len_int[0]) || (pos_int[0] == video_len_int[0] && pos_int[1] > video_len_int[1]))
            {
                pos_int[0] = video_len_int[0];
                pos_int[1] = video_len_int[1];
            }
        }
    }
    if (is_range(pos_int, op_start_int, op_end_int))
    {
        pos_int[0] = op_end_int[0];
        pos_int[1] = op_end_int[1];
    }

    string answer = ""; // mm:ss
    bool flag = true;
    for (int p : pos_int)
    {
        string temp = to_string(p);
        if (temp.length() == 1)
        {
            answer += "0";
        }
        answer += temp;
        if (flag)
        {
            answer += ":";
            flag = false;
        }
    }
    return answer;
}