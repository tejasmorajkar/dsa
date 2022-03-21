#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int A)
{
    vector<int> result(A+1, 0);
    result[0] = 1;
    for(int i=1; i<A+1; i++)
        for(int j=i; j>=1; j--)
            result[j] += result[j-1];
    return result;
}

vector<int> solve(int A)
{
    vector<int> result;
    int prev = 1; // NC0 = 1
    result.push_back(prev);
    for (int i = 1; i <= A; i++)
    {
        int current = (prev * (A-i+1))/i;
        result.push_back(current);
        prev = current;
    }
    return result;
}

int main()
{
    int A = 4;
    vector<int> result = solve(A);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
