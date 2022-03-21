#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int A, int B, int C, int D) 
{
    vector<int> result {1};
    int a_index = 0, b_index = 0, c_index = 0, count = 0, prev_element = INT32_MIN;
    while (count < D)
    {
        int min_value = min({A * result[a_index], B * result[b_index], C * result[c_index]});
        if (min_value == A * result[a_index])
        {
            a_index++;
        }
        if (min_value == B * result[b_index])
        {
            b_index++;
        }
        if (min_value == C * result[c_index])
        {
            c_index++;
        }
        if (min_value > prev_element)
        {
            result.push_back(min_value);
            count++;
            prev_element = min_value;
        }
    }
    //Remove 1 from start
    result.erase(result.begin());
    return result;
}

int main()
{
    int A = 3, B = 2, C = 7, D = 3;
    vector<int> result = solve(A,B,C,D);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}