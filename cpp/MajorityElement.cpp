#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Using hashmap
// TC: O(n)
// SC: O(n)
int solve(const vector<int> &A)
{
    int result;
    int N = A.size();
    unordered_map<int, int> map;
    int max_count = INT32_MIN;
    for (int i = 0; i < N; i++)
    {
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = 1;
        }
        else
        {
            map[A[i]]++;   
        }
        if (map[A[i]] > N/2)
        {
            return A[i];
        }
    }
    return -1;
}

// Using Moore's Voting Algorithm (Game of thrones/ Last man standing)
int solve2(const vector<int> &A)
{
    int N = A.size();
    
    if (N == 0)
    {
        return -1;
    }

    if (N == 1)
    {
        return A[0];
    }

    int majority_index = 0;
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (A[i] == A[majority_index])
        {
            count++;
        }
        else if (count == 1)
        {
            majority_index = i;
            count = 1;
        }
        else
        {
            count--;
        }
    }
    return A[majority_index];
}

int main()
{
    vector<int> A {5,5,1,2,3,5,5};
    int result = solve(A);
    cout << result << endl;
    return 0;
}