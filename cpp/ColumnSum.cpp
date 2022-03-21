#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<int> solve(vector<vector<int>> A)
{
    vector<int> result;
    int column_sum = 0;
    for (int column = 0; column < A[0].size(); column++)
    {
        for (int row = 0; row < A.size(); row++)
        {
            column_sum += A[row][column];
        }
        result.push_back(column_sum);
        column_sum = 0;
    }
    return result;
}

int main()
{
    vector<vector<int>> A{{1,2,3,4},{5,6,7,8},{9,2,3,4}};
    vector<int> result = solve(A);
    print_array(result);
	return 0;
}