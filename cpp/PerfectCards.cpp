#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solve(vector<int> &A)
{
    unordered_map<int, int> map;
    for (int i = 0; i < A.size(); i++)
    {
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = 1;
        }
        else
        {
            map[A[i]]++;
        }
    }
    if (map.size() != 2) {
        return "LOSE";
    }
    int player1_count = 0;
    int player2_count = 0;
    bool player1_turn = true;
    for (auto &it : map)
    {
        // Player 1 turn
        if (player1_turn)
        {
            player1_count += it.second;
            player1_turn = false;
        }
        else
        {
            // Player 2 turn
            player2_count += it.second;
        }
    }
    if (player1_count == player2_count)
    {
        return "WIN";
    } else {
        return "LOSE";
    }
}

int main()
{
    vector<int> A{1, 1, 2, 2, 3};
    string result = solve(A);
    cout << result << endl;
    return 0;
}